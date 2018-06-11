#sudo apt-get -f install
check_opencv_installed=$(pkg-config --modversion opencv)
#check_opencv_version_installed
#pkg-config --exact-version=2.4 opencv
#if [ ${#check_opencv_installed} == 0 ]; then
#	a="$(pkg-config --modversion opencv)"
#	if [ "$a" \> "2.4" ]; then
		#sudo -s
		find / -name "*opencv*" -exec rm -fr {} \;
		echo "Upgrading ubuntu"
		#sudo apt-get update
		#sudo apt-get upgrade

		echo "Installl dependencies"
		#sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
		#sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
		#sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
		#sudo apt-get install python-dev python-pip python3-dev python3-pip
		#sudo -H pip2 install -U pip numpy
		#sudo -H pip3 install -U pip numpy
		#sudo apt-get install libprotobuf-dev protobuf-compiler
		#sudo apt-get install libxine2-dev libv4l-dev
		#sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
		
		
		echo "Downloading and Installing opencv library"
		#CURR_PTH="$PWD"
		cd /opt
		git clone https://github.com/Itseez/opencv.git
		git clone https://github.com/Itseez/opencv_contrib.git

		echo "Build and install OpenCV"; echo ' '
		#cd opencv_contrib; git checkout 2.4; cd ..;
		cd opencv
		git checkout 2.4
		mkdir release
		cd release
		echo "Inside release"; echo ' '
		cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
		make -j4
		echo "Before install"; echo ' '
		make install
		echo "After install"; echo ' '
		ldconfig
		exit
		#cd $CURR_PTH

		echo ' '
		echo "The version of openCV installed is: "
		pkg-config --modversion opencv; echo ' '