cd MODI_raw_F1; make clean; cd ..;
cd MODI_retina_F1; make clean; cd ..;
cd MODI_raw_F2; make clean; cd ..;
cd MODI_retina_F2; make clean; cd ..;
cd MODI_raw_F3; make clean; cd ..;
cd MODI_retina_F3; make clean; cd ..;
cd MODI_raw_F4; make clean; cd ..;
cd MODI_retina_F4; make clean; cd ..;
cd MODI_raw_F5; make clean; cd ..;
cd MODI_retina_F5; make clean; cd ..;
cd MODI_raw_F6; make clean; cd ..;
cd MODI_retina_F6; make clean; cd ..;
cd NEAT; make clean; cd ..
cd RobotLib; make clean; cd ..
cd ../HyperNEAT-master;	make clean; cd ../Practica
cd docs; make cleandocs; cd ..;
if [[ -d "../opencv-2.4.13.3/build" && -f "../opencv-2.4.13.3/build/Makefile" ]]; then
	cd ../opencv-2.4.13.3/build; make unistall; cd ..
	rm -rf build; cd ../Practica
fi 
