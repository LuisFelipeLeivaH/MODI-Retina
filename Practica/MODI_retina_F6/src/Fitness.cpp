#ifndef FITNESS_CPP
#define FITNESS_CPP

#include "Fitness.hpp"
#include "RIAR.hpp"
#include <cmath>

Fitness::Fitness()
{
	fitness = FAILED_FITNESS;
	h_distance = FITNESS_BASE;
	zone = zone_1;
	next_cube = 0;
	saturation_counter = 0;
	max_cube_reached = 0;
	df = 1.4660;				// Position for the first cube. Same as y_1[0]
}

Fitness::~Fitness()
{

}

void Fitness::measuringValues(vector < double > position, double rightVel, double leftVel, vector<double> y_1, unsigned long int *bonus_tc, unsigned long int *bonus_tz,
								long int *sim_time, unsigned long int *discount_t, unsigned int *n_colision, bool champion)
{
	robot_position.push_back(position);
	robot_rightVel.push_back(rightVel);		// Not used in this implementation
	robot_leftVel.push_back(leftVel);		// Not used in this implementation
	Zones zone_prev = zone;
	zone = (position.at(0) > LIM_WALLx_2) ? zone_1:	
		   (position.at(0) > LIM_WALLx_3) ? zone_2:	
		   (position.at(0) > LIM_WALLx_4) ? zone_3:
		   (position.at(0) > LIM_WALLx_5) ? zone_4:
		   finish;	

	//cout << "sim_time: " << *sim_time << endl;		  
	if(zone != zone_prev)
	{
		*n_colision = 0;
		*sim_time -= BONUS_TIME;	// bonus_tz
	}

	// An extra time is given when changing zones
	*bonus_tz = (zone-1)*BONUS_TIME;

	// An extra time is given when the robot pass by a cube
	// This has to be extended for the whole maze

	unsigned int start = (zone == zone_1) ? 0 :
						 (zone == zone_2) ? N_CUBES_ZONE_1 : 
						 (zone == zone_3) ? N_CUBES_ZONE_2 :
						 (zone == zone_4) ? N_CUBES_ZONE_3 : 
						 N_CUBES_ZONE_4;

	unsigned int fend = (zone == zone_1) ? N_CUBES_ZONE_1 :
						(zone == zone_2) ? N_CUBES_ZONE_2 : 
						(zone == zone_3) ? N_CUBES_ZONE_3 :
						(zone == zone_4) ? N_CUBES_ZONE_4 : 
						N_CUBES_ZONE_4;						 

	if(zone == zone_1 || zone == zone_3)
	{
		for(unsigned int i=start; i < fend; i++)
		{
			if (position.at(1) > y_1.at(i))
			{
				/*cout << "He pasado el cubo " << i << endl;

				// Colision punishment is done by proccessColisions in RIAR.cpp
				 This algorithm may be improved
				if(*n_colision > 2)	
				{
					cout << "Tengo " << *n_colision << " colisiones" << endl;				
				}			
					
				else
				{
					cout << "Colisiones <= 2 (" << *n_colision << ")" << endl;
				}*/

				if(next_cube == i)
				{
					next_cube++;

					*sim_time -= (i*BONUS_TIME - *bonus_tc == 0) ? 0 :
								(i*BONUS_TIME - *bonus_tc <  (unsigned long int) *sim_time) ? (long int) (i*BONUS_TIME - *bonus_tc) : 
								*sim_time;

					*bonus_tc = i*BONUS_TIME;	

					if( i > max_cube_reached )
					{
						max_cube_reached = i;
					}				

				}
				
				//std::cout << "bonus_tc = " << *bonus_tc << std::endl;			// for debbug
				break;
			}
		}
	}

	else if(zone == zone_2 || zone == zone_4)
	{
		for(unsigned int i=start; i < fend; i++)
		{
			if (position.at(1) < y_1.at(i))
			{
				/*cout << "He pasado el cubo " << i << endl;*/

				// Colision punishment is done by proccessColisions in RIAR.cpp
				/*if(*n_colision > 2)	
				{
					cout << "Tengo " << *n_colision << " colisiones" << endl;				
				}			
					
				else
				{
					cout << "Colisiones <= 2 (" << *n_colision << ")" << endl;
				} */

				if(next_cube == i)
				{
					next_cube++;
					
					*sim_time -= (i*BONUS_TIME - *bonus_tc == 0) ? 0 :
								(i*BONUS_TIME - *bonus_tc <  (unsigned long int) *sim_time) ? (long int) (i*BONUS_TIME - *bonus_tc) : 
								*sim_time;

					*bonus_tc = i*BONUS_TIME;

					if( i > max_cube_reached )
					{
						max_cube_reached = i;
					}	
				}
				//std::cout << "bonus_tc = " << *bonus_tc << std::endl;			// for debbug
				break;
			}
		}
	}
	
	else
	{
		cout << "Congratulations: You've reached the Finish Zone!" << endl;
	}
				

	// If the robot is halted for more than FINISH_FOR_IDLE measures, all the bonus times are reseted to zero
    if( ((*sim_time + *bonus_tc + *bonus_tz) % FINISH_FOR_IDLE == 0 ) && ( (int) robot_position.size() >= (FINISH_FOR_IDLE-TIME_INIT_MEASURING)/DELTA_TIME ) )
    {
    	bool halted = true;
    	double x0 = position.at(0);
    	double y0 = position.at(1);
    	long int N = (FINISH_FOR_IDLE-TIME_INIT_MEASURING)/DELTA_TIME;

    	/*cout << "Checkeando si esta parado el robot..." << endl;
    	cout << "N: " << N << ", robot_position.size() - N: " << robot_position.size() - N << endl;*/
    	for(unsigned int i=robot_position.size()-2; i > robot_position.size() - N; i--) 
    	{
    		double x1 = robot_position.at(i).at(0);
        	double y1 = robot_position.at(i).at(1);

        	if((x1 > x0 + HALTED_THRESHOLD || x1 < x0 - HALTED_THRESHOLD) || (y1 > y0 + HALTED_THRESHOLD || y1 < y0 - HALTED_THRESHOLD))
        	{
        		halted = false;
        		//cout << "No esta parado!" << endl;
        		break;
        	}
    	}

    	// Finish the simulation
    	if(halted && !champion)
    	{
    		cout << "Halted!" << endl;
    		*sim_time = TIME_SIMULATION;
    	}
    }

    if(leftVel - rightVel >= MAX_SPEED_DIF || rightVel - leftVel >= MAX_SPEED_DIF )
    {
        saturation_counter++;
        if (saturation_counter >= MAX_DIFF_SATURATION)
        {
        	cout << "Robot caught in saturation state longer than the maximum allowed!" << endl;
    		*sim_time = TIME_SIMULATION;
        }

    }
    else
    {
        saturation_counter=0;
    }


}

double Fitness::calculateFitness(unsigned int n_colision, const vector <double> &y_1)
{		

	
    for(int i = 1; i < (int)robot_position.size(); i++)
    {
    	
        double x1 = robot_position.at(i).at(0);
        double y0 = robot_position.at(i - 1).at(1);
        double y1 = robot_position.at(i).at(1);
        
        // Add here all stages where the robot moves towards -->
        if ( (x1 < LIM_WALLx_1 && x1 > LIM_WALLx_2) || (x1 < LIM_WALLx_3 && x1 > LIM_WALLx_4) || (x1 < LIM_WALLx_5 && x1 > LIM_WALLx_6) ) 
        {
        	h_distance += y0-y1;	// y axis is horizontal and increases to the left 
        }

		// Add here all stages where the robot moves towards <--
		else if( (x1 < LIM_WALLx_2 && x1 > LIM_WALLx_3) || (x1 < LIM_WALLx_4 && x1 > LIM_WALLx_5) )
		{
			h_distance += y1-y0;	// y axis is horizontal and increases to the left
		}	      
		else continue;  
    }  

    
    /*
    df = y_1[max_cube_reached];

    if( robot_position.back().at(0) < LIM_WALLx_1 && robot_position.back().at(0) > LIM_WALLx_2 || 
    	robot_position.back().at(0) < LIM_WALLx_3 && robot_position.back().at(0) > LIM_WALLx_4)
    {
    	double sigmoid = 1/(1+exp(SIGM_G*(df - h_distance)));
    }    

    fitness = (zone == zone_1)? sigmoid: 
			  (zone == zone_2)? LIM_ZONE1 + zone_2*(sigmoid - LIM_ZONE1) + FITNESS_END_ZONE1:
			  (zone == zone_3)? LIM_ZONE2 + zone_3*(sigmoid - LIM_ZONE2) + FITNESS_END_ZONE2: 
			  (zone == zone_4)? LIM_ZONE3 + zone_4*(sigmoid - LIM_ZONE3) + FITNESS_END_ZONE3: 
			  (zone == finish)? LIM_ZONE4 + finish*(sigmoid - LIM_ZONE4) + FITNESS_END_MAZE:
			  FAILED_FITNESS;
	*/
	double y_fin = robot_position.back().at(1);
	if(zone == zone_1)
	{
		double sigmoid = 0;
		for(int i=0; i < N_CUBES_ZONE_1; i++) {
			sigmoid += 1/(1+exp(-SIGM_G*( y_1[i] - y_fin )));
		}
			
		fitness = sigmoid;
		
	}
	else if(zone == zone_2)
	{
		double sigmoid = 0;
		for(int i=N_CUBES_ZONE_1; i < N_CUBES_ZONE_2; i++) {
			sigmoid += 1/(1+exp(-SIGM_G*( y_fin - y_1[i] )));
		}
			
		fitness = N_CUBES_ZONE_1 + sigmoid;
	}
	else if(zone == zone_3)
	{
		double sigmoid = 0;
		for(int i=N_CUBES_ZONE_2; i < N_CUBES_ZONE_3; i++) {
			sigmoid += 1/(1+exp(-SIGM_G*( y_1[i] - y_fin )));
		}
			
		fitness = N_CUBES_ZONE_1 + N_CUBES_ZONE_2 + sigmoid;
	}
	else if(zone == zone_4)
	{
		double sigmoid = 0;
		for(int i=N_CUBES_ZONE_3; i < N_CUBES_ZONE_4; i++) {
			sigmoid += 1/(1+exp(-SIGM_G*( y_fin - y_1[i] )));
		}
			
		fitness = N_CUBES_ZONE_1 + N_CUBES_ZONE_2 + N_CUBES_ZONE_3 + sigmoid;
	}
	else if(zone == finish)
	{
		fitness = N_CUBES_ZONE_1 + N_CUBES_ZONE_2 + N_CUBES_ZONE_3 + N_CUBES_ZONE_4;
	}
	else
	{
		fitness = FAILED_FITNESS;
	}

	/*
	fitness = (zone == zone_1)? h_distance: 
			  (zone == zone_2)? LIM_ZONE1 + zone_2*(h_distance - LIM_ZONE1) + FITNESS_END_ZONE1:
			  (zone == zone_3)? LIM_ZONE2 + zone_3*(h_distance - LIM_ZONE2) + FITNESS_END_ZONE2: 
			  (zone == zone_4)? LIM_ZONE3 + zone_4*(h_distance - LIM_ZONE3) + FITNESS_END_ZONE3: 
			  (zone == finish)? LIM_ZONE4 + finish*(h_distance - LIM_ZONE4) + FITNESS_END_MAZE:
			  FAILED_FITNESS;
	*/

	if(n_colision > 0){
		fitness/= pow((1+COLISION_COMPOUND_FACTOR), (n_colision+1));
	}

	fitness = (fitness < FAILED_FITNESS) ? FAILED_FITNESS : fitness;   

    generation_fitness.push_back(fitness);

	return fitness;
}

void Fitness::resetPopulationValues()
{
	fitness = FAILED_FITNESS;
	h_distance = FITNESS_BASE;
	zone = zone_1;
	robot_position.clear();
	robot_rightVel.clear();
	robot_leftVel.clear();
	next_cube = 0;
	saturation_counter = 0;
}

void Fitness::resetGenerationValues()
{
	generation_fitness.clear();
}


double Fitness::getFitness()
{
	return fitness;
}

double Fitness::getDistance()
{
	return h_distance;
}

vector < double > Fitness::getGenerationFitness()
{
	return generation_fitness;
}


#endif
