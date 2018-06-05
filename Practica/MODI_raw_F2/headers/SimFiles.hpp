#ifndef SIMFILES_HPP
#define SIMFILES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <stdlib.h> 
#include "CalcFunctions.hpp"

using namespace std;

/**
    @author Oscar Silva
    @date Sep 30, 2016
*/

/**
*	A class responsible for creating simulation files.
*
*	An instantiation of this class creates the files and foldiers related with the Champion and its respective fitness, 
*	wheels velocities and instant position. 
*	This also creates a summary of the entire program as a results file.
*	All these files may be found in simulations_files foldier after the program is run, but the champion will be created
*	only when the entire trainings finish.
*
*/

class SimFiles
{
	ofstream file_results;
	ofstream file_fitness;
	ofstream file_champions;

	ofstream file_robotPosition;
	ofstream file_robotMotorVelocity;

public:

	/**
	*	@brief 	Creates files for fitness, results and champions
	*	
	*	This constructor creates a file to store the average and standard deviation of the fitness for each generation.
	*	It also creates a file to store the fitness for every population in each generation.
	*	Finally it creates a file to store the fitness and population for the champion at each generation.
	*
	*/
	SimFiles();

	/**
	*	@brief 	Closes the opened files of fitness, results and champions
	*
	*/
	~SimFiles();

	/**
	*	@brief Appends the generation, population and fitness to the results file
	*	@param fitness A valid fitness for the current generation and population
	*	@param generation The current generation
	*	@param population The current population
	*	@see SimFiles()
	*
	*/
	void addFileResults(double fitness, int generation, int population);

	/**
	*	@brief Appends the generation, the average fitness and its standard deviation to the fitness file
	*	@param fitness The fitness of every population in the current generation
	*	@param generation The current generation
	*	@see SimFiles()
	*
	*/
	void addFileFitness(vector < double > fitness, int generation);

	/**
	*	@brief Appends the generation, population and fitness to the champions file
	*	@param fitness Fitness of the champion for the current generation
	*	@param generation Current generation
	*	@param population Population of the champion for the current generation
	*	@see SimFiles()
	*
	*/
	void addFileChampion(double fitness, int generation, int population);

	/**
	*	@brief Creates a file for the movements of the given generation and population
	*	@param generation Current generation
	*	@param population Current population
	*	
	*	Creates a file of the form movement_G<generation>P<population>.txt.
	*	The file of the champion is later copied to a file named
	*	movement/Champion_G<generation>P<population>.txt and the other files are deleted.
	*
	*/
	void openRobotMovementFile(int generation, int population);

	/**
	*	@brief Closes the robot movement file
	*	@see openRobotMovementFile(int, population)
	*
	*/
	void closeRobotMovementFile();

	/**
	*	@brief Appends given data to the robot movement file
	*	@param sim_time Simulation time
	*	@param position Current robot's position
	*	@param orientation Gamma angle in euler angles (alpha, beta and gamma).
	*
	*
	*/
	void addRobotMovementFile(double sim_time, vector < double > position, double orientation);

	/**
	*	@brief Creates a file for the velocity of the given generation and population
	*	@param generation Current generation
	*	@param population Current population
	*
	*	Creates a file of the form motorVelocity_G<generation>P<population>.txt.
	*	The file of the champion is later copied to a file named
	*	motorVelocity/Champion_G<generation>P<population>.txt and the other files are deleted.
	*
	*/

	void openRobotMotorVelocityFile(int generation, int population);

	/**
	*	@brief Closes the robot velocity file
	*	@see openRobotMotorVelocityFile(int, int)
	*
	*/
	void closeRobotMotorVelocityFile();

	/**
	*	@brief Appends given data to the robot movement file
	*	@param sim_time Simulation time
	*	@param rightVel Current right wheel velocity
	*	@param leftVel Current left wheel velocity
	*
	*
	*/
	void addRobotMotorVelocityFile(double sim_time, double rightVel, double leftVel);
};

#endif
