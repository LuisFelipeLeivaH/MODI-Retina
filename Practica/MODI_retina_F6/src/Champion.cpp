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
    
    if(argc != 4)
    {
        cerr << "ERROR: The number of arguments is incorrect" << endl;
        cerr << "argc = " << argc << endl;
        
        for(int i=0; i < argc; i++)
        {
            cerr << "argv[" << i << "] = " << argv[i] << endl;
        }

        cerr << "Enter:\targ_1 = genetic_encoding_file\t arg_3 = port_number";
        return -1;
    }

    Fitness * fitness = new Fitness();
    RobotVREP * vrep = new RobotVREP(false, atoi(argv[3]));
    Retina * retina = new Retina(); 


    // ============= VREP INITIALIZATIONS ============= //
    
    Joint * rightWheel = new Joint((char*)"SCALE", (char*)"motor_der");
    Joint * leftWheel = new Joint((char*)"SCALE", (char*)"motor_izq");
    vrep->addJoint(rightWheel);
    vrep->addJoint(leftWheel);

    VisionSensor * visionSensor = new VisionSensor((char*)"VisionSensor");
    vrep->addVisionSensor(visionSensor);

    Object * centerDummy = new Object((char*)"modi_dummy");
    Object * Modi = new Object((char*)"MODI");
    vrep->addObject(centerDummy);
    vrep->addObject(Modi);

    CollisionObject * chasis = new CollisionObject((char*)"Collision_MODI_1#");
    CollisionObject * rueda1 = new CollisionObject((char*)"Collision_MODI_2#");
    CollisionObject * rueda2 = new CollisionObject((char*)"Collision_MODI_3#");
    vrep->addCollisionObject(chasis);
    vrep->addCollisionObject(rueda1);
    vrep->addCollisionObject(rueda2);
    vector < CollisionObject * > structure = {chasis, rueda1, rueda2};

    vector < Object * > cubes;    

    // Set random position of Obstacles

    vector <double> x_1 = {1.9875, 1.1875, 0.2875, -0.4125, -0.8875};

    vector <double> y_1 = {1.7660, 1.3340, 0.9400, 0.389, -3.0001e-3, -0.4120, -0.8260, -1.342,
                           -1.32, -.8344, -.3488, .1368, .6224, 1.108,
                           1.256, .595, 8.0006e-3, -.546, -1.2050,
                           -1.021, -.409, .203, .791,
                           .708, .327, .087, -.433, -.935, -1.3820,
                           -1.4290, -.957, -.419, .073, .317, .713};

    vector <double> x_fRow = {2.16875, 1.80625, 1.9875, 2.16875, 1.80625, 1.9875,2.16875, 1.80625};

    // {x, y, delta, axis of variance (0 = x, 1 = y)}                        
    vector<vector<double>> threshold_cubes = { {1.6250, -1.8495, .2991, 1}, {.75, 1.80725, .33015, 1}, 
                            {-.175, -1.85025, .29865, 1}, {-1.1250, 1.80725, .33015, 1}, {-.65, 1.2940, .2375, 0} }; 

    // First cube rows
    double fRow_space = LIM_WALLx_1 - LIM_WALLx_2;                          

    for (int i=0;i < 8; i++){
        stringstream sstm1;
        sstm1 << "Obstacle" << i<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = rand()%201 - 100;

        vector < double > position;

        if((i+1)%3 == 0)
        {
            position.push_back(x_fRow[i] + rand1/100*.2620);
            position.push_back(y_1[i]);
            position.push_back(0.05);
            vrep->setObjectPosition(obstacle, position);
            cubes.push_back(obstacle);
        }

        else
        {
            position.push_back(x_fRow[i] + rand1/100*(fRow_space/2)/3.3);
            position.push_back(y_1[i]);
            position.push_back(0.05);
            vrep->setObjectPosition(obstacle, position);
            cubes.push_back(obstacle);            
        }
        
    }

    // Second cube rows
    for (int i=8;i < 14; i++){
        stringstream sstm1;
        sstm1 << "Obstacle" << i<< "#";

        Object * obstacle = new Object((char*)sstm1.str().c_str());
        vrep->addObject(obstacle);

        double rand1 = rand()%201 - 100;
        //double rand2 = rand()%201 - 100;

        vector < double > position;

        position.push_back(x_1[1] + rand1/100*.2620);
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

    vector < double *> output(ADITIONAL_HYPERNEAT_INPUTS,NULL);
    vector < double *> input(NX*NY+ADITIONAL_HYPERNEAT_INPUTS,NULL);        
    Genetic_Encoding * organism = new Genetic_Encoding;
    organism->load(argv[2]);

     // ========== HYPERNEAT INITIALIZATIONS =========== //    

    for(int k = 0; k < NX*NY; k++)
    {
        double * pixel = new double;
        input.at(k) = pixel;            
    }

    // One for differential velocity and another for common wheel velocity
    for(int k = NX*NY, l = 0; k < NX*NY + ADITIONAL_HYPERNEAT_INPUTS; k++, l++)
    {
        double * vIn = new double;
        double * vOut = new double;
        input.at(k) = vIn;
        output.at(l) = vOut;
    }
    //cout << "The size of input is: " << input.size() << endl;
    //cout << "The size of output is: " << output.size() << endl;

    HyperNeat * hyperneat = new HyperNeat(input, output, argv[1]);

    // Create all substrate connections according to CPPN-NEAT result
    if(!hyperneat->createSubstrateConnections(organism))
    {
        clog << "ERROR: Neat organism has not created substrate connections successfully" << endl;
        return(0);
    }


    // ================================================ //

    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
        
    long int sim_time = 0;
    long unsigned int t_recovery = 0;
    unsigned long int t_recoil = 0;
    unsigned long int bonus_tc = 0;         // passing by a cube
    unsigned long int bonus_tz = 0;         // passing to the next zone
    unsigned long int discount_t = 0;       // colisions
    unsigned int n_colision = 0;
    bool flag = true;
    int flag_times = 0;
    double rightVel = 0.0;
    double leftVel = 0.0;
    double L_ANN = 0;
    double R_ANN = 0;
    double inverse_v = 0;
    // double diff_v = 0;                      // differential wheel velocity
    // double speed_up = 0;                    // increasement in both wheels velocity        

    vrep->setJointTargetVelocity(rightWheel, 0.0);
    vrep->setJointTargetVelocity(leftWheel, 0.0);

    double rand1 = (rand()%101)/5000;    
    double rand3= rand()%201-100;

    double upperBorder = -2.3230;
    double rightBorder = -2.3230;

    vector < double > position, orientation;

    position.push_back(-upperBorder*15/16/*+rand1*/);   // vertical
    position.push_back(-rightBorder*15/16+rand1);       // horizontal
    position.push_back(3.0110e-02);

    orientation.push_back(0);
    orientation.push_back(0);
    orientation.push_back((1 + (rand3/100)/5)*M_PI);
    
    vrep->setObjectPosition(Modi, position);
    vrep->setObjectOrientation(Modi, orientation);

    unsigned char * image;
    Mat frameRGB = Mat(NX, NY, CV_8UC3);
    Mat frameGRAY = Mat(NX, NY, CV_8UC1);          

    vrep->startSimulation(simx_opmode_oneshot_wait);        

    while(sim_time < (TIME_SIMULATION - (long int) discount_t) && flag )
    {                
        if(sim_time > TIME_INIT_MEASURING)
        {
            position = vrep->getObjectPosition(centerDummy);
            orientation = vrep->getObjectOrientation(centerDummy);            

            proccessColisions(vrep->readCollision(structure), &n_colision, vrep, leftWheel, rightWheel, &discount_t, &t_recovery, &t_recoil, &sim_time);
            fitness->measuringValues(position, rightVel, leftVel, y_1, &bonus_tc, &bonus_tz, &sim_time, &discount_t, &n_colision, true);

            if (abs(orientation.at(0)) > 0.78 || abs(orientation.at(1)) > 0.78)
            {
                flag_times++;
                if(flag_times > 10) flag = false;
            }else
                flag_times = 0;
        }

        image = vrep->getVisionSensorImage(visionSensor);  
        frameRGB.data = image;
        flip(frameRGB, frameRGB, 0);
        cvtColor(frameRGB,frameGRAY,CV_BGR2GRAY);
        
        Mat tmp = frameGRAY;
        Mat frame = tmp;

        tmp = retina->GetImg(frame);

        resize(tmp, frame, Size(0,0) , 6.0, 6.0, (int)INTER_NEAREST );
        imshow( "Display window", frame );
        waitKey(10);

        for(int i = 0; i < NY; i++)
        {
            for(int j = 0;j < NX; j++)
            {
                *input.at(i*NX + j) = (double)frame.at<uchar>(i,j)/255*2-1;
            }
        }
        
        if(t_recoil > 0)
        {
            *input.at(NX*NY) = (double)( ( rightVel - inverse_v*DEFAULT_SPEED )/( MAX_SPEED_DIF/2 ));      // between -1 and 1
            *input.at(NX*NY + 1) = (double)(( leftVel - inverse_v*DEFAULT_SPEED )/( MAX_SPEED_DIF/2 ) );   // between -1 and 1 
        }
        else
        {
            *input.at(NX*NY) = (double)( ( rightVel - DEFAULT_SPEED )/( MAX_SPEED_DIF/2 ));      // between -1 and 1
            *input.at(NX*NY + 1) = (double)(( leftVel - DEFAULT_SPEED )/( MAX_SPEED_DIF/2 ) );   // between -1 and 1 
            //*input.at(NX*NY) = (double)( diff_v )/( MAX_SPEED_DIF + speed_up/2 + 1 );  // between -1 and 1
            //*input.at(NX*NY+1) = (double)( speed_up )/( MAX_VEL - DEFAULT_SPEED +1 );  // between -1 and 1
        }

        *input.at(NX*NY+2) = (t_recoil>0) ? 1 : 0;   // Colisions


        // Allows to obtain the final HyperNeat outputs. 
        hyperneat->evaluateSubstrateConnections();                
        
        L_ANN += *output.at(1);
        R_ANN += *output.at(0);
        inverse_v = *output.at(2);
       
        if(t_recoil > 0)
        {
            rightVel = inverse_v*(  DEFAULT_SPEED + floor((R_ANN - L_ANN)/SPEED_STEP)*SPEED_STEP/2  );
            leftVel = inverse_v*(  DEFAULT_SPEED + floor((L_ANN - R_ANN)/SPEED_STEP)*SPEED_STEP/2  ); 
            //cout << "t_recoil = " << t_recoil << "\tinverse_v = " << inverse_v << endl;
        }

        else if(L_ANN - R_ANN >= MAX_SPEED_DIF)
        {
            R_ANN = rightVel = -MAX_SPEED_DIF/2;
            L_ANN = leftVel = MAX_SPEED_DIF/2; 
        }

        else if (R_ANN - L_ANN >= MAX_SPEED_DIF)
        {
            R_ANN = rightVel = MAX_SPEED_DIF/2;
            L_ANN = leftVel = -MAX_SPEED_DIF/2; 
        }

        else
        {
            rightVel = DEFAULT_SPEED + floor((R_ANN - L_ANN)/SPEED_STEP)*SPEED_STEP/2;
            leftVel = DEFAULT_SPEED + floor((L_ANN - R_ANN)/SPEED_STEP)*SPEED_STEP/2; 
        }                

        vrep->setJointTargetVelocity(rightWheel,-rightVel);
        vrep->setJointTargetVelocity(leftWheel,leftVel);

        usleep(DELTA_TIME - EXECUTION_TIME);
        sim_time += DELTA_TIME;
    }            

    vrep->stopSimulation(simx_opmode_oneshot_wait);

    delete(vrep);
    
    return(0);
}

void proccessColisions(bool colision, unsigned int *n_colision, RobotVREP * vrep, Joint * leftWheel, Joint * rightWheel, 
    unsigned long int *discount_t, unsigned long int *t_recovery, unsigned long int *t_recoil, long int *sim_time)
{
    if(colision && *t_recovery == 0)
    {        
        //double leftVel, rightVel;
        //leftVel = rightVel = -DEFAULT_SPEED*RECOIL_FACTOR;
        //vrep->setJointTargetVelocity(rightWheel,-rightVel);
        //vrep->setJointTargetVelocity(leftWheel,leftVel);  
        //usleep(TIME_RECOIL);
        *t_recoil = TIME_RECOIL;
        *t_recovery = TIME_RECOVERY;
        if(*n_colision > 2)
        {            
            *discount_t += DISCOUNT_TIME;
        }

        (*n_colision)++;
    }
    else if(*t_recovery > 0)
    {
        *t_recovery  -= (DELTA_TIME < *t_recovery) ? DELTA_TIME: *t_recovery;
    }

    if(*t_recoil>0)
    {
        *t_recoil -= (DELTA_TIME < *t_recoil) ? DELTA_TIME : *t_recoil ;
    }
}