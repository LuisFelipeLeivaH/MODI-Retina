if ! [[ -d RobotLib ]]
	then
	echo "Downloading RobotLib library from git repository"
	git clone https://github.com/osilvam/RobotLib.git
	cd RobotLib; make; sudo make install; cd ..;
else
	cd RobotLib
	git remote update
	LOCAL=$(git rev-parse @)
	REMOTE=$(git rev-parse @{u})
	if [ $LOCAL = $REMOTE ]
		then
		echo "RobotLib is already downloaded and Up-to-date"
		cd ..
	else
		cd ..
		rm -f -R RobotLib
		echo "Downloading RobotLib library from git repository"
		git clone https://github.com/osilvam/RobotLib.git
		cd RobotLib; make; sudo make install; cd ..;
	fi
fi

VREPF=$(ls -d */ | grep V-REP)
cd $VREPF
if ! [[ -f MultiVrep.sh ]]
	then
	cp ../MultiVrep.sh .
fi
cd ..

if ! [[ -d NEAT ]]
	then
	echo "Downloading NEAT library from git repository"
	git clone https://github.com/osilvam/NEAT.git
	cd NEAT; make; sudo make install; cd ..;
else
	cd NEAT
	git remote update
	LOCAL=$(git rev-parse @)
	REMOTE=$(git rev-parse @{u})
	if [ $LOCAL = $REMOTE ]
		then
		echo "NEAT is already downloaded and Up-to-date"		
		cd ..
	else
		cd ..
		rm -f -R /NEAT
		echo "Downloading NEAT library from git repository"
		git clone https://github.com/osilvam/NEAT.git
		cd NEAT; make; sudo make install; cd ..;
	fi
fi

if [[ ! -d "../HyperNEAT-master" ]]; then
	echo "ERROR: HyperNEAT foldier is missing"
else
	cd ../HyperNEAT-master; make install; cd ../Practica
fi

#sudo apt-get -f install
#check_opencv_installed="$(pkg-config --modversion opencv)"
found_opencv=$(pkg-config --errors-to-stdout --modversion opencv | grep "not found")
#pkg-config --exact-version=2.4 opencv
#if [[ ${#check_opencv_installed} == 0 ]]; then
if [[ "" == "$found_opencv" ]]; then	
	version="$(pkg-config --modversion opencv)"
	echo $version
	if [ "$version" != "2.4.13.3" ]; then
		sudo find / -path "*/MODI-Retina*" -prune -o -name "*opencv*" -print -exec rm -fr {} \;

		if [[ ! -d "../opencv-2.4.13.3" ]]; then
			echo "ERROR: please download in MODI-Retina foldier the opencv version 2.4.13.3 from: https://opencv.org/releases.html and try again"	

		else	
			if [[ -d "../opencv-2.4.13.3/build" && -f "../opencv-2.4.13.3/build/Makefile" ]]; then
				echo "Exists Makefile"
				echo "Uninstalling and beginning a clean installation"
				cd ../opencv-2.4.13.3/build; make unistall; cd ..
				rm -rf build; cd ../Practica

			else
				echo "No built"
			fi

			echo "Upgrading ubuntu"
			sudo apt-get update
			sudo apt-get upgrade

			echo "Installl dependencies"
			sudo apt-get install build-essential
			sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
			sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
			sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
			sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
			sudo apt-get install python-dev python-pip python3-dev python3-pip
			sudo -H pip2 install -U pip numpy
			sudo -H pip3 install -U pip numpy
			sudo apt-get install libprotobuf-dev protobuf-compiler
			sudo apt-get install libxine2-dev libv4l-dev
			sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
			
			
			echo "Installing opencv library"
			cd ../opencv-2.4.13.3/
			mkdir -p build
			cd build
			cmake -DCMAKE_BUILD_TYPE=Release -DWITH_FFMPEG=OFF -DCMAKE_INSTALL_PREFIX=/usr/local ..
			make -j7 # runs 7 jobs in parallel
			sudo make install

			echo ' '
			echo "The version of openCV installed is: "
			pkg-config --modversion opencv; echo ' '
			cd ../../Practica

			sudo echo "/usr/local/lib/" > opencv.conf
			sudo mv opencv.conf /etc/ld.so.conf.d/
			sudo ldconfig -v

			cd MODI_raw_F1; make; cd ..;
			cd MODI_raw_F2; make; cd ..;
			cd MODI_raw_F3; make; cd ..;
			cd MODI_raw_F4; make; cd ..;
			cd MODI_raw_F5; make; cd ..;
			cd MODI_retina_F1; make; cd ..;
			cd MODI_retina_F2; make; cd ..;
			cd MODI_retina_F3; make; cd ..;
			cd MODI_retina_F4; make; cd ..;
			cd MODI_retina_F5; make; cd ..;

			./CreateDelete_docs.bash
		fi

	else
		echo "Opencv 2.4.13.3 is already installed"
	fi

else

	if [[ ! -d "../opencv-2.4.13.3" ]]; then
		echo "ERROR: please download in MODI-Retina foldier the opencv version 2.4.13.3 from: https://opencv.org/releases.html and try again"	

	else	
		if [[ -d "../opencv-2.4.13.3/build" && -f "../opencv-2.4.13.3/build/Makefile" ]]; then
			echo "Exists Makefile"
			echo "Uninstalling and beginning a clean installation"
			cd ../opencv-2.4.13.3/build; make unistall; cd ..
			rm -rf build; cd ../Practica

		else
			echo "No built"
		fi

		echo "Upgrading ubuntu"
		sudo apt-get update
		sudo apt-get upgrade

		echo "Installl dependencies"
		sudo apt-get install build-essential
		sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
		sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
		sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
		sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
		sudo apt-get install python-dev python-pip python3-dev python3-pip
		sudo -H pip2 install -U pip numpy
		sudo -H pip3 install -U pip numpy
		sudo apt-get install libprotobuf-dev protobuf-compiler
		sudo apt-get install libxine2-dev libv4l-dev
		sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
		
		
		echo "Installing opencv library"
		cd ../opencv-2.4.13.3/
		mkdir -p build
		cd build
		cmake -DCMAKE_BUILD_TYPE=Release -DWITH_FFMPEG=OFF -DCMAKE_INSTALL_PREFIX=/usr/local ..
		make -j7 # runs 7 jobs in parallel
		sudo make install

		echo ' '
		echo "The version of openCV installed is: "
		pkg-config --modversion opencv; echo ' '
		cd ../../Practica

		sudo echo "/usr/local/lib/" > opencv.conf
		sudo mv opencv.conf /etc/ld.so.conf.d/
		sudo ldconfig -v

		cd MODI_raw_F1; make; cd ..;
		cd MODI_raw_F2; make; cd ..;
		cd MODI_raw_F3; make; cd ..;
		cd MODI_raw_F4; make; cd ..;
		cd MODI_raw_F5; make; cd ..;
		cd MODI_retina_F1; make; cd ..;
		cd MODI_retina_F2; make; cd ..;
		cd MODI_retina_F3; make; cd ..;
		cd MODI_retina_F4; make; cd ..;
		cd MODI_retina_F5; make; cd ..;

		./CreateDelete_docs.bash

	fi
fi

