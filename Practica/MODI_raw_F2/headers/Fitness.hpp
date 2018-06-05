#ifndef FITNESS_HPP
#define FITNESS_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "CalcFunctions.hpp"

using namespace std;

#define FAILED_FITNESS 0.00001
#define FITNESS_BASE 0.00001

/**
	A fitness class for meassuring the performance of the different generations. 
	
	The performance is higher as the robot travel higher distances in the forward direction (i.e. if the robot moves
	backwards the performance is the lowest). Note that this works with the distance as a vector for every measure it
	takes. So if between measurements the robot ends up in the same point the fitness added to the minimum possible will 
	be zero. But, if after two measurements the robot finishes in the same point, the fitness added will not be zero.
	In order to compute the fitness it is a must to make different measurements so that the object
	has enough data to decide whether the current simulation is valid or not. 
	If the robot crushes with something the measurement will not be considered a valid datum and both the current and previous
	measurement will be discarded as a way of punishment in the final fitness.

*/

class Fitness
{
	double fitness;
	double distance;
	vector < vector < double > > robot_position;
	vector < double > robot_tail;	
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
	*	@brief Keeps track of the position and velocity of the robot, whether it is moving forward or backwards and if it is crushing somewhere 
	*	@param position A vector representing the robot position
	*	@param rightVel The instant right wheel velocity
	*	@param leftVel The instant left wheel velocity
	*	@param collision True if the robot is colliding somewhere
	*
	*	This function member adds the instant vector of position and velocity everytime it is invoked.
	*	The data is stored in the current object.
	*	It also computes if in the current measure the robot is in reverse and stores it.
	*	If the robot crushes with something the measurement will not be considered a valid datum and both the current and previous
	*	measurement will be discarded as a way of punishment in the final fitness.
	*
	*/
	void measuringValues(vector < double > position, double rightVel, double leftVel, bool collision);

	/**
	*	@brief Computes the fitness for the current simulation
	*	@return The fitness of the current simulation
	*	@see measuringValues(vector < double >, double, double, bool)
	*
	*	In order to have a valid simulation this member function makes sure the robot changes his wheels' velocities more
	*	than a certain threshold and that the robot is not moving backwards. If at least one of these conditions is met the
	*	value returned will be the minimum possible fitness. The fitness is computed adding a weighted value of the traveled
	*	distance between measurements done by calling measuringValues. This value of the fitness and distance is stored in the 
	*	object and it keeps track of the fitness per generation.
	*
	*/
	double calculateFitness();

	/**
	*	@brief Clears the object's vector of position, reverse, and right and left wheel speed
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
