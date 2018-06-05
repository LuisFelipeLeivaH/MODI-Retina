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
#include "Retina.hpp"
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
*	@author Oscar Silva
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

    MODI_raw_F1:

		This experiment does not detect the collides made by the robot, but it does detect when it moves
		backwards. The experiment worries that the individual wheels of the robot change their
		velocity independently. The fitness is computed taking into account every distance covered between 
		measurements during the simulation. The raw input image is sent to NEAT.

	MODI_raw_F2:

		This experiment detects collides made by the robot so that it can be taken into account by the
		fitness. It also detects when the robot moves backwards. The experiment worries that the 
		individual wheels of the robot change their	velocity independently. The fitness is computed taking 
		into account every distance covered between measurements during the simulation. The raw input image is sent to NEAT.

	MODI_raw_F3:

		This experiment does not detect the collides made by the robot and it does not mind if the robot is moving backwards
		or not, but it does mind the change in movement direction instead of the changes in the speed of the wheels
		themselves. This experiment computes the fitness in terms of how much distance it covers between the initial
		measurement and the last one in the entire simulation. The raw input image is sent to NEAT.

	MODI_retina_F1:

		This experiment does not detect the collides made by the robot, but it does detect when it moves
		backwards. The experiment worries that the individual wheels of the robot change their
		velocity independently. The fitness is computed taking into account every distance covered between 
		measurements during the simulation. The input image is processed by the Retina encoder before going to NEAT.

	MODI_retina_F2:

		This experiment detects collides made by the robot so that it can be taken into account by the
		fitness. It also detects when the robot moves backwards. The experiment worries that the 
		individual wheels of the robot change their	velocity independently. The fitness is computed taking 
		into account every distance covered between measurements during the simulation. The input image is processed 
		by the Retina encoder before going to NEAT.

	MODI_retina_F3:

		This experiment does not detect the collides made by the robot and it does not mind if the robot is moving backwards
		or not, but it does mind the change in movement direction instead of the changes in the speed of the wheels
		themselves. This experiment computes the fitness in terms of how much distance it covers between the initial
		measurement and the last one in the entire simulation. The input image is processed 
		by the Retina encoder before going to NEAT.

*/


#endif
