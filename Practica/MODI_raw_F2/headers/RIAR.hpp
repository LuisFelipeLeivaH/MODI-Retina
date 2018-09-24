#ifndef RIAR_HPP
#define RIAR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <time.h>
#include <sys/time.h>
#include <fstream>
#include <NEAT>
#include <ROBOTLIB>
#include "CalcFunctions.hpp"
#include "Fitness.hpp"
#include "SimFiles.hpp"
//#include <typeinfo>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;
using namespace ANN_USM;

#define NX 32 // X image resolution
#define NY 32 // Y image resolution

//#define TIME_SIMULATION 10000 // milliseconds
#define TIME_SIMULATION 16000000 // microseconds
#define TIME_INIT_MEASURING 1000000 // microseconds

#define DELTA_TIME 50000 // microseconds
#define EXECUTION_TIME 25000

#define MAX_VEL 8 //rad/s
#define MIN_VEL 0 //rad/s


/**
*	@mainpage RIAR and Champion
*	@author Oscar Silva and Luis Leiva
*	@date Sep 30, 2016
*	@see Original repository: https://github.com/osilvam/Practica
*
	We  built  a  robot  able  to  navigate  autonomously  in  a  simulated  environment.
	To  process  visual  information  and  generate  the  corresponding  motor  actions,
	the  robot  relies  in  an  image  encoder  based  in  the  mammalian  retina.  For  this
	purpose,  the  encoder  was  used  as  an  input  for  an  evolving  neural  network  that
	was  trained  with  a  genetic  algorithm,  allowing  the  robot  to  learn  how  to  effi-
	ciently  avoid  objects.

	The  main  features  of  the  retina-inspired  encoder  are  a  Difference  of  Gaus-
	sians  (DoG)  spatial  filter  and  a  Difference  of  Exponentials  (DoE)  temporal
	filter,  to  mimic  the  ON-OFF  ganglion  cells  in  the  retina.  This  approach  allows
	the  detection  of  edges  and  movement  using  only  a  fraction  of  the  information
	contained  in  the  original  input  image 

	Patricio Cerda.
	Maria José Escobar.
	A. Palacios

	RIAR.cpp:

		Creates a NEAT training using a simulation of a robot in a maze with help of V-REP. In this case 
		the algorithm for computer vision is without the retina encoder.
		In the end of the entire simulations a champion file with its respective movement and velocity files
		are created so that the champion executable can be loaded.

	Champion.cpp:

		Program intended to run the champion simulation of the last training made. 
    	In order to use this program, the whole training must be completed.

    MODI_raw_F1, MODI_raw_F2, MODI_raw_F3:

    	In these cases the robot is placed in the middle of a board with a lot of cubes placed randomly. The 
    	robot gains fitness basically in terms of the distance covered in the simulation in any direction. The 
    	simulation time is constant between simulations and all NEAT outputs are sent directly to the individual 
    	wheels velocity. In all cases the robot is free to do whatever it wants in the simulation time, but when 
    	it does a behavior that the experiment is worried about the fitness is penalized. All wheels are given a 
    	minimum and maximum velocity. A more detailed description about the differences between these ones and 
    	their corresponding retina versions are shown below as characteristic for each simulation. Note that 
    	these experiments are the original ones created by the first author, Oscar Silva.

    MODI_raw_F1:

    	This experiment penalize fitness if the robot moves backwards. 
    	If the robot's individual wheels do not change their velocity in the simulation more than a fixed criteria 
    	the fitness is said to be invalid.
    	If the fitness is valid, the fitness is equal to the sum of the distances cover between every measurement 
    	during the simulation.

	MODI_raw_F2:

		This experiment penalize fitness if the robot moves backwards and if the robot collides with something.
		Everything else is the same as MODI_raw_F1. 

	MODI_raw_F3:

		This experiment does not detect the collides made by the robot and it does not mind if the robot is moving backwards
		or not, but it does mind the change in movement direction instead of the changes in the velocity of the wheels
		themselves. If they do not change the differential velocity more than a fixed criteria the fitness is said to be invalid.
		This experiment computes the fitness in terms of how much distance it covers between the initial
		measurement and the last one in the entire simulation. In other words, the fitness is equal to the magnitude of the distance 
		vector which starts in the middle of the board and finishes in the last measurement point of the robot in the simulation.

    MODI_raw_F4, MODI_raw_F5 and MODI_raw_F6:

		In these experiments it was decided to use a new maze-like scene with cubes put randomly. The board was split into 5 different 
		zones with a growing difficulty, and the robot gets fitness while it is approaching to the finish zone. The robot detects the 
		collisions and recoils for a little period of time so the cube can be put in the visual domain in case it was not seen by the 
		robot and gives the chance to recover. If the robot colides more than 2 times the fitness is punished and the time of simulation 
		decrease. If the robot is halted for more than a fixed period of time the simulation stops. The same happens if the robot is turning
		on its own axis longer than a desired time. The simulation time can increase if the robot is behaving the way we want but stops relatively 
		fast otherwise. 
		In the case of MODI_raw_F4, NEAT decides in the speed of each individual wheel between a range of minimum and maximum speed, whereas in 
		MODI_raw_F5 NEAT decides the differential speed for the wheels with a default "idle" speed. In this last case there is a maximum differential 
		speed, and if NEAT tries to get it over, the robot starts rotating on its axis. In the case of MODI_raw_F6 is exactly the same as in MODI_raw_F5
		but it is run with an implementation of HyperNEAT, and NEAT is only used to create the CPPN for that neural network.

	MODI_retina_F1, MODI_retina_F2, MODI_retina_F3, MODI_retina_F4, MODI_retina_F5 and MODI_retina_F6:

    	The only difference between MODI_raw_FX and its respective MODI_retina_FX is that the first one send the raw input image to NEAT 
    	while the latter send it after processing it with the Retina encoder.
  

	
*/


#endif
