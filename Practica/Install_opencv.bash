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