#ifndef FITNESS_HPP
#define FITNESS_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "CalcFunctions.hpp"

using namespace std;

#define FAILED_FITNESS	0.00001
#define FITNESS_BASE	0.00001
#define FITNESS_END_ZONE1	0.4
#define FITNESS_END_ZONE2	0.8
#define FITNESS_END_ZONE3	1.6	
#define FITNESS_END_MAZE	2
#define LIM_WALLx_1	2.35
#define LIM_WALLx_2	1.625
#define LIM_WALLx_3	0.75
#define LIM_WALLx_4	-0.175
#define LIM_WALLx_5 -1.1250
#define LIM_WALLx_6	-2.35
#define LIM_ZONE1	4.05925
#define LIM_ZONE2	7.2155
#define LIM_ZONE3	10.27175
#define LIM_ZONE4	13.228
#define LIM_START	2.1578
#define COLISION_COMPOUND_FACTOR	0.2		// percentage of compound interest by which the fitness decrease with collisions
#define FINISH_FOR_IDLE	4500000		// Finishes simulation time after FINISH_FOR_IDLE usec without moving
#define HALTED_THRESHOLD	0.0003	// distance units
#define N_CUBES_ZONE_1	8
#define N_CUBES_ZONE_2	6
#define N_CUBES_ZONE_3	9
#define N_CUBES_ZONE_4	6	// Twice this number but the cubes are placed in the same 'y' coordinate



/**
	A fitness class for meassuring the performance of the different generations. 
	
	The robot gets higher fitness as it travels through the maze. 
	The maze is divided in zones, and everytime the robot reaches a higher zone it gets a fitness bonus and the 
	fitness given by unit of distance increases.
	When the robot has collisions the fitness decrease with a compound factor. The simulation time decreases as well if 
	the robot has more than 2 collisions. Everytime the robot passes by a cube the simulation time increases. When 
	the robot gets a higher zone the simulation time increases as well.
	If the robot is halted for more than FINISH_FOR_IDLE microsecs the simulation stops.


*/

class Fitness
{
private:
	double fitness;
	double h_distance;	
	enum Zones {zone_1=1, zone_2, zone_3, zone_4, finish};
	Zones zone = zone_1;	
	unsigned int next_cube;
	vector < vector < double > > robot_position;
	vector < double > robot_rightVel;
	vector < double > robot_leftVel;
	vector < double > generation_fitness;

public:	

	/**
		\brief Constructor
	*/
	Fitness();

	/**
		\brief Destructor
	*/
	~Fitness();

	/**
	*	@brief Keeps track of the position, velocity, zone, colisions of the robot
	*	@param position A vector representing the robot position
	*	@param rightVel The instant right wheel velocity
	*	@param leftVel The instant left wheel velocity
	*	@param y_1 Cubes' horizontal position
	*	@param bonus_tc A pointer to the bonus time after passing by a cube
	*	@param bonus_tz A pointer to the bonus time after changing a zone
	*	@param sim_time The current simulation time
	*	@param discount_t The discount time in case several colisions are done			
	*	@param n_colision A pointer to the number of colisions the robot has done
	*
	*	This function member adds the instant vector of position and velocity everytime it is invoked.
	*	It also keeps track of the zone the robot is in and restart the collisions counter if the robot reaches a new zone.
	*	If the robot passes to another zone or passes by a cube an extra simulation time is given
	*	Also checks if the robot is halted and stops the simulation if it happens for more than FINISH_FOR_IDLE microseconds
	*
	*/
	void measuringValues(vector < double > position, double rightVel, double leftVel, vector <double> y_1, unsigned long int *bonus_tc, unsigned long int *bonus_tz, 
						long int *sim_time, unsigned long int *discount_t, unsigned int *n_colision);

	/**
	*	@brief Computes the fitness for the current simulation
	*	@param n_colision The number of colisions the robot has done
	*	@return The fitness of the current simulation
	*	@see measuringValues(vector < double >, double, double)
	*
	*	This member function computes the fitness based on the horizontal distance traveled inside the maze in every zone,
	*	the maximum zone reached, and the number of collisions the robot has done so far.
	*	This value of the fitness and distance is stored in the object and it keeps track of the fitness per generation.
	*
	*/
	double calculateFitness(unsigned int n_colision);

	/**
	*	@brief Clears the object's vector of position and right and left wheel speed
	*	
	*	Reset the vectors of the current population so a new one can be tested.
	*	The vector of the current generation is kept.
	*
	*/
	void resetPopulationValues();

	/**
	*	@brief Clears the object's generation fitness
	*
	*	Reset the current generation fitness so a new one can be tested.	
	*
	*/
	void resetGenerationValues();

	/**
	*	@brief Not implemented
	*
	*/
	double getFrecuency();

	/**
	*	@brief Gives the fitness
	*	@return The last computed fitness
	*	@see calculateFitness()	
	*
	*/
	double getFitness();

	/**
	*	@brief Gives the distance
	*	@return The last computed distance
	*	@see calculateFitness()	
	*
	*/
	double getDistance();

	/**
	*	@brief Used to get the current generation fitness
	*	@return A vector of double with the fitness per generation
	*	@see calculateFitness()		
	*
	*/
	vector < double > getGenerationFitness();

};

#endif
