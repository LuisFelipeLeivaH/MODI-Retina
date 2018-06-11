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

If you want to understand more about the project please generate its documentation (see Documentation section). A document in html and latex will be created. To open the document in html you need a browser and open the 'docs' foldier, then in 'html' and finaly open the file 'index.html'

## Authors

* **Oscar Silva** - *Working program* - [osilvam](https://github.com/osilvam/)
* **Luis Leiva**  - *Documentation*	  - [LuisFelipeLeivaH](https://github.com/LuisFelipeLeivaH)

## Acknowledgments

* Patricio Cerda
* Maria José Escobar
* A. Palacios


