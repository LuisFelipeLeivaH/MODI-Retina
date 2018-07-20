# MODI + RETINA

We built a robot able to navigate autonomously in a simulated environment. To process visual information and generate the corresponding motor actions, the robot relies in an image encoder based in the mammalian retina. For this purpose, the encoder was used as an input for an evolving neural network that was trained with a genetic algorithm, allowing the robot to learn how to effi- ciently avoid objects.

The main features of the retina-inspired encoder are a Difference of Gaus- sians (DoG) spatial filter and a Difference of Exponentials (DoE) temporal filter, to mimic the ON-OFF ganglion cells in the retina. This approach allows the detection of edges and movement using only a fraction of the information contained in the original input image

Patricio Cerda
Maria José Escobar
A. Palacios

This project is split in six different trainings, from which three of them implement the retina encoder. The only difference between a raw and a retina training is that the first ones use the raw input image as a source of information, while the second ones filter the image before giving it to the learning system. The specific differences between each experiment is explained in the project's documentation (see section Installing).

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. This instructions are intended to a Linux machine, and are tested in Ubuntu 18.04 LTS. If you are using another operating system, it is likely that you will have to install manually all the software auto-installled by the bash scripts given in the project. The content of such scripts are explained in the Installing section.

### Prerequisites

The first thing you need to install in your computer is git. On Ubuntu, type

```
sudo apt install git-all
```

You need to have installed 'make'. If you do not, type the following in terminal:

```
sudo apt-get install build-essential
```

In order to generate the documentation you need to install 'doxygen':

```
sudo apt-get install aptitude
aptitude install doxygen
aptitude install texlive
aptitude install graphviz
```

Download Anaconda and follow the instructions given on the official webpage. The following link works fine:

https://conda.io/docs/user-guide/install/linux.html


### Installing

First open a temrinal in the foldier you want to have your project, and clone this version of the repository form github. This document assumes you are using this repo.

```
git clone https://github.com/LuisFelipeLeivaH/MODI-RETINA.git
```

You may want to clone the original reposiroty as well. This is not recommended since it does not have the project documentation

```
git clone https://github.com/osilvam/Practica
```

After cloning either the new or the original version of the project, in the terminal go to the 'Practica' foldier and execute the installing script

```
./Install.bash
```
This scripts installs the following repositories and will ask you if you want to create the documentation of the project.

* [RobotLib](https://github.com/osilvam/RobotLib.git) - V-REP for making a virtual robot simulation
* [NEAT](https://github.com/osilvam/NEAT.git) - NEAT library from git repository
* [HyperNEAT] - HyperNEAT library already given in this repository
* [OpenCV](https://opencv.org/releases.html) - opencv library for computer vision and all needed packages
* [Simulations] - All six simulations with and without retina encoder
* [Documentation] - Asks you if you wish to create the documentation right away

If you have any problem installing openCV, please see the following link:

https://docs.opencv.org/3.4.1/d7/d9f/tutorial_linux_install.html
https://opencv.org/releases.html

Remember to download the release 2.4.13.3 since in newer versions a namespace is added and many names change their names.

### Documentation

At the end of the installation the Install.bash script will ask you if you want to create the documentation at the moment or later. 

If you want to create the documentation afterwards you need to type in terminal (in the 'Practica' foldier) the following command, and follow the instructions given:

```
./CreateDelete_docs.bash
```

You have the option of creating only the documentation for MODI_raw_F1 which has full details of how the classes work in that training and the main differences with the other ones. You may choose to create the documentation for all MODI_raw trainings so you will have full documentation of the project without the retina encoder. You may also want to create the documentation for all projects. If you do not want to create the documentation type n (no). In every affirmative case the documentation for RobotLib is created.

If you want to erase the documentation you have to open a terminal in 'Practica/docs' and then type:

```
sudo make cleandocs
```

### Cleaning the project

If you want to erase the training files or for some reason the executable is corrupted or edited and you need to reinstall it you may have to go to the 'Practica' foldier and then execute the following in the terminal. It will erase the documentation too. 

```
./CleanAll.bash
```

This is useful if you want to upload the contents in git, for example.


## Running the tests

You have to go to the 'Practica' foldier, open a terminal and type:

```
./Execute.bash
```
maybe you will need to give execution privileges before running it

```
chmod 744 Execute.bash
```

Follow the instructions given by the program in the terminal. Then, the program will ask you to choose between running a Training or the Champion. Do not choose Champion unless a complete training has been done before (i.e. choose Training and wait until the program finishes itself).

Once the entire training has been completed a copy with all training simulations information will be copied to a matlab/data foldier right after the MODI_r* foldier. This documents are needed for the data analysis but the champion runs with the information stored in the bin foldier.

If you want to understand more about the project please generate its documentation (see Documentation section). A document in html and latex will be created. To open the document in html you need a browser and open the 'docs' foldier, then in 'html' and finally open the file 'index.html'

## Data analysis 

### Individual plots per MODI foldier

In each MODI foldier you will find a 'matlab' foldier where there is a python script called 'processResults.py'. You can run this script to analyze the fitness and champions results given in the training stage. A new foldier will be created in the 'matlab' foldier called 'graphs', where you will find plots in pdf format for each scene. If one scene is not yet completed the graphs will be in yellow without data plotted. It will be created a bar plot for the activation functions as well.

### General analysis for the entire project

In the foldier called 'practica' there are two scripts for analyzing the information in all MODI's trainings. The first and recommended is to simulate with the python script 'processResults.py' which will create a 'simulation_graphs' foldier in docs (i.e. ./docs/simulation_graphs) with all the graphs for fitness and champions altogether in a subplot in pdf format. This is done for every scene. In case a simulation has not been done yet its respective plot will be yellow without any data, but all other plot will be sucessfully created. It will be created a bar plot for the activation functions as well.

If you want to run the plots in MATLAB you can use the 'plot_fitness.m' script. In this case, you need to enter the number of scene to simulate (i.e. '1' for the red cubes scene, and '2' for the cubes with the leaves scene). The plots for the simulations that haven't been done yet will be displayed without a problem as blank plots, and the other plots will be sucessfully created.

## Possible complications

Sometimes the simulation is overwhelmed by "not existent nodes" and the Champion cannot be loaded. In order to avoid this, when the NEAT repository is downloaded please go to 'Practica' foldier and then go to 'Practica/NEAT/src/genetic_encoding.cpp'. Here you have to comment all outputs that say 'o << "\t\t\t{\"exist\": " << Lnode_genes[i].exist ;' in the function member 'string Genetic_Encoding::JSON()'. If you do not want to do this yourself, please replace this function member for the following code:

```
string Genetic_Encoding::JSON(){
	int 			node_size 		(Lnode_genes.size());
	int 			connection_size (Lconnection_genes.size());
	stringstream 	o;
	o << "{\n\t\"Genetic_Encoding\":\n\t{" ;


	o << "\n\t\t\"row_order\":\n\t\t[\n\t\t\t";
	for (int i = 0; i < (int)row_orderer_list.size(); ++i)
	{
		o << row_orderer_list[i];
		if(i < (int)row_orderer_list.size()-1)
			o << ",";
		else{
			o << "\n\t\t]";
		}
	}

	o << "\n\t\t\"nodes\":\n\t\t[\n";
	for (int i = 0; i < node_size; ++i)
	{
		if(Lnode_genes[i].exist)
			o << "\t\t\t{\"exist\": " << Lnode_genes[i].exist  << ",\"node\": " <<Lnode_genes[i].node << ",\"type\": " << Lnode_genes[i].type << ", \"row\": " << Lnode_genes[i].row << ", \"function\": \"" << Lnode_genes[i].random_function.str_name << "\"";
//		else
//			o << "\t\t\t{\"exist\": " << Lnode_genes[i].exist ;
		if(i<node_size-1)
			o <<  "},\n";
		else
			o <<  "}\n";
	}

	o << "\t\t],\n\t\t\"connection_genes\":\n\t\t[\n";
	for (int i = 0; i < connection_size; ++i)
	{
		if(Lconnection_genes[i].exist)
			o << "\t\t\t{\"exist\": " << Lconnection_genes[i].exist << ",\"innovation\": " << Lconnection_genes[i].innovation << ",\"in\": " << Lconnection_genes[i].in << ",\"out\": " << Lconnection_genes[i].out << ",\"weight\": " << Lconnection_genes[i].weight << ",\"enable\": " << Lconnection_genes[i].enable;
//		else
//			o << "\t\t\t{\"exist\": " << Lconnection_genes[i].exist;

		if(i<connection_size-1)
			o <<  "},\n";
		else
			o <<  "}\n";
	}

	o << "\t\t]\n\t}\n}";
	return o.str();
}
```


## Authors

* **Oscar Silva** - *Working program* - [osilvam](https://github.com/osilvam/)
* **Luis Leiva**  - *Documentation/Simulations* - [LuisFelipeLeivaH](https://github.com/LuisFelipeLeivaH)

## Acknowledgments

* Patricio Cerda
* Maria José Escobar
* A. Palacios



