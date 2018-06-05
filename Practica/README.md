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

Download Anaconda and follow the instructions given on the official webpage. The following link worked for me:

https://conda.io/docs/user-guide/install/linux.html


### Installing

First open a temrinal in the foldier you want to have your project, and clone this version of the repository form github

```
pending...
```

You may want to clone the original reposiroty as well. This is not recommended since it does not have the project documentation

```
git clone https://github.com/osilvam/Practica
```

After cloning either the new or the original version of the project, in the terminal go to the 'Practica' foldier and execute the installing script

```
./Install.bash
```
If this did not work, you would have to install by yourself the following programs:

* [RobotLib](https://github.com/osilvam/RobotLib.git) - V-REP for making a virtual robot simulation
* [NEAT](https://github.com/osilvam/NEAT.git) - NEAT library from git repository
* [OpenCV](https://github.com/Itseez/opencv.git) - opencv library for computer vision (see the end of this section if a problem is found)


At the end of the script you will be asked if you want to generate the documentation of the project. You have the option of creating only the documentation for MODI_raw_F1 which has full details of how the classes work in that training and the main differences with the other ones. You may choose to create the documentation for all MODI_raw trainings so you will have full documentation of the project without the retina encoder. You may want to create the documentation for all projects as well. If you do not want to create the documentation type n (no). In every case the documentation for RobotLib is created.

If you want to create the documentation afterwards you need to type in terminal (in the 'Practica' foldier) the following command, and follow the instructions given:

```
./CreateDelete_docs.bash
```

If for some reason the executable is corrupted and you need to reinstall it or you want to erase the training files and restart a new simulation you may have to go to the 'Practica' foldier and then execute the following in the terminal. 

```
./CleanAll.bash
```

In this version of Ubuntu (18.04 LTS) I had a problem trying to install OpenCV as it should normally be installed, so I used the following tutorial to installed it

http://www.codebind.com/linux-tutorials/install-opencv-3-2-ubuntu-18-04-lts-linux/

If you have any problem installing OpenCV with the previous tutorial, maybe is because you had problems installing flex. You will need to install 'aptitude' and then install 'flex'. The following links may help you out:

https://askubuntu.com/questions/164293/how-to-install-flex
https://askubuntu.com/questions/557629/how-to-install-flex-and-bison-error-can-not-locate-file


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

## Authors

* **Oscar Silva** - *Working program* - [osilvam](https://github.com/osilvam/)
* **Luis Leiva**  - *Documentation*	  - [LuisFelipeLeivaH](https://github.com/LuisFelipeLeivaH)

## Acknowledgments

* Patricio Cerda
* Maria José Escobar
* A. Palacios

