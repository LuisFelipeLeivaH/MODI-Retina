#include "RIAR.hpp"

/* V-REP implementation of an Autonomous Robot that avoid obstacles and advances without
preferred direction. The algotithm uses NEAT to evolve. */

/**
    @author Oscar Silva
    @date Sep 30, 2016
*/


int main(int argc, char* argv[])
{
    srand (time(0));        
    
    if(argc < 3)
    {
        cerr << "ERROR: The number of arguments is incorrect" << endl << "Enter:\targ_1 = genetic_encoding_file\t arg_3 = port_number";
        return -1;
    }

    RobotVREP * vrep = new RobotVREP(false, atoi(argv[2]));
    Retina * retina = new Retina(); 


    // ============= VREP INITIALIZATIONS ============= //
    
    Joint * rightWheel = new Joint((char*)"SCALE", (char*)"motor_der");
    Joint * leftWheel = new Joint((char*)"SCALE", (char*)"motor_izq");
    vrep->addJoint(rightWheel);
    vrep->addJoint(leftWheel);

    VisionSensor * visionSensor = new VisionSensor((char*)"VisionSensor");
    vrep->addVisionSensor(visionSensor);

    Object * Modi = new Object((char*)"MODI");
    vrep->addObject(Modi);

    vector < Object * > cubes;    

    // Set random position of Obstacles

    vector <double> x_1 = {1.9875, 1.1875, 0.2875, -0.4125, -0.8875};

    vector <double> y_1 = {1.7660, 1.3340, 0.9400, 0.389, -3.0001e-3, -0.4120, -0.8260, -1.342,
                           -1.32, -.8344, -.3488, .1368, .6224, 1.108,
                           1.256, .595, 8.0006e-3, -.546, -1.2050,
                           -1.021, -.409, .203, .791,
                           .708, .327, .087, -.433, -.935, -1.3820,
                           -1.4290, -.957, -.419, .073, .317, .713};

    // {x, y, delta, axis of variance (0 = x, 1 = y)}                        
    vector<vector<double>> threshold_cubes = { {1.6250, -1.8495, .2991, 1}, {.75, 1.80725, .33015, 1}, 
                            {-.175, -1.85025, .29865, 1}, {-1.1250, 1.80725, .33015, 1}, {-.65, 1.2940, .2375, 0} };                           

    // First and second cube rows
    for (int i=0;i < 14; i++){
        stringstream sstm1;
        sstm1 << "Obstacle" << i<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = rand()%201 - 100;
        //double rand2 = rand()%201 - 100;

        vector < double > position;

        position.push_back(x_1[i/8] + rand1/100*.2620);
        position.push_back(y_1[i]);
        position.push_back(0.05);

        vrep->setObjectPosition(obstacle, position);

        cubes.push_back(obstacle);
    }

     // Third cube rows
    for (int i=14;i < 23; i++){
        stringstream sstm1;
        sstm1 << "Obstacle" << i<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = rand()%201 - 100;
        //double rand2 = rand()%201 - 100;

        vector < double > position;

        position.push_back(x_1[2] + rand1/100*.2620);
        position.push_back(y_1[i]);
        position.push_back(0.05);

        vrep->setObjectPosition(obstacle, position);

        cubes.push_back(obstacle);
    }

    // Fourth cube rows
    for (int i=23;i < 35; i++){
        stringstream sstm1;
        sstm1 << "Obstacle" << i<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = rand()%201 - 100;
        //double rand2 = rand()%201 - 100;

        vector < double > position;

        position.push_back(x_1[3+i/29]+ rand1/100.0*.1);
        position.push_back(y_1[i]);
        position.push_back(0.05);

        vrep->setObjectPosition(obstacle, position);

        cubes.push_back(obstacle);
    }

    // Threshold cubes
    for(unsigned int i=0; i < threshold_cubes.size(); i++)
    {
        stringstream sstm1;
        sstm1 << "Obstacle" << i+35<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = (rand()%201 - 100)/100.0;
        //double rand2 = rand()%201 - 100;

        vector < double > position;

        if(threshold_cubes[i][3] == 0)  // delta in x axis
        {
            position.push_back(threshold_cubes[i][0]+ rand1*threshold_cubes[i][2]);
            position.push_back(threshold_cubes[i][1]);
        }
        else if(threshold_cubes[i][3] == 1) // delta in y axis
        {
            position.push_back(threshold_cubes[i][0]);
            position.push_back(threshold_cubes[i][1]+ rand1*threshold_cubes[i][2]);
        }
        else // delta coordinate error
        {
            position.push_back(threshold_cubes[i][0]);
            position.push_back(threshold_cubes[i][1]);
        }
        
        position.push_back(0.05);

        vrep->setObjectPosition(obstacle, position);

        cubes.push_back(obstacle);
    }


    // ================================================ //


    // ========== NEAT INITIALIZATIONS =========== //

    vector < double > output(2,0.0);
    vector < double > input(NX*NY+2,0.0);

    Genetic_Encoding champion;
    champion.load(argv[1]);

    // ================================================ //
        
    int sim_time = 0;
    double rightVel = 0.0;
    double leftVel = 0.0;

    vrep->setJointTargetVelocity(rightWheel, 0.0);
    vrep->setJointTargetVelocity(leftWheel, 0.0);

    double rand1 = rand()%201 - 100;
    double rand2 = rand()%201 - 100;
    double rand3 = rand()%201 - 100;

    vector < double > position, orientation;

    position.push_back(rand1/100*.10);
    position.push_back(rand2/100*.10);
    position.push_back(0.03011);

    orientation.push_back(0);
    orientation.push_back(0);
    orientation.push_back(rand3/100*M_PI);
    
    vrep->setObjectPosition(Modi, position);
    vrep->setObjectOrientation(Modi, orientation);

    unsigned char * image;
    Mat frameRGB = Mat(NX, NY, CV_8UC3);
    Mat frameGRAY = Mat(NX, NY, CV_8UC1);          

    vrep->startSimulation(simx_opmode_oneshot_wait);        

    while(sim_time < TIME_SIMULATION)
    {                
        image = vrep->getVisionSensorImage(visionSensor);  
        frameRGB.data = image;
        flip(frameRGB, frameRGB, 0);
        cvtColor(frameRGB,frameGRAY,CV_BGR2GRAY);
        
        Mat tmp = frameGRAY;
        Mat frame = tmp;

        tmp = retina->GetImg(frame);


        resize(tmp, frame, Size(0,0) , 6.0, 6.0, (int)INTER_NEAREST );

        for(int i = 0; i < NY; i++)
        {
            for(int j = 0;j < NX; j++)
            {
                input.at(i*NX + j) = (double)frame.at<uchar>(i,j)/255*2-1;
            }
        }
        
        input.at(NX*NY) = (double)((2.0/(MAX_VEL - MIN_VEL))*(rightVel - MIN_VEL) - 1.0);
        input.at(NX*NY + 1) = (double)((2.0/(MAX_VEL - MIN_VEL))*(leftVel - MIN_VEL) - 1.0);

        output = champion.eval(input);

        rightVel = output.at(0) + rightVel;
        leftVel = output.at(1) + leftVel;

        if(rightVel > MAX_VEL) rightVel = MAX_VEL;
        else if(rightVel < MIN_VEL) rightVel = MIN_VEL;
        if(leftVel > MAX_VEL) leftVel = MAX_VEL;
        else if(leftVel < MIN_VEL) leftVel = MIN_VEL;

        vrep->setJointTargetVelocity(rightWheel,-rightVel);
        vrep->setJointTargetVelocity(leftWheel,leftVel);

        usleep(DELTA_TIME - EXECUTION_TIME);
        sim_time += DELTA_TIME;
    }            

    vrep->stopSimulation(simx_opmode_oneshot_wait);

    delete(vrep);
    
    return(0);
}
