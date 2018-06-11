cleandocs:
	@rm -f -R ./MODI_raw_F1
	@rm -f -R ./MODI_raw_F2
	@rm -f -R ./MODI_raw_F3
	@rm -f -R ./MODI_retina_F1
	@rm -f -R ./MODI_retina_F2
	@rm -f -R ./MODI_retina_F3
	cd ../RobotLib/; make cleandocs; cd ../docs
	cd ../../opencv-2.4.13.3/build/doc; rm -rf doxygen; cd ../../../Practica/docs
	cd ../../HyperNEAT-master/doc; rm -rf html; cd ../../Practica/docs
	cd ../NEAT; rm -fr documentation; cd ../docs


MODI_all:
	cd ../RobotLib; make docs; cd ../docs;
	cd ../NEAT/; make doc; cd ../docs;
	cd ../../HyperNEAT-master/; make docs; cd ../Practica/docs;
	cd ../../opencv-2.4.13.3/build/; make doxygen; cd ../../Practica/docs;
	
	#@mkdir -p ./MODI_raw_F1
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1
	#@mkdir -p ./MODI_raw_F2
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F2
	#@mkdir -p ./MODI_raw_F3
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F3
	#@mkdir -p ./MODI_retina_F1
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F1
	#@mkdir -p ./MODI_retina_F2
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F2
	#@mkdir -p ./MODI_retina_F3
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F3	

MODI_raw_F1:
	cd ../RobotLib; make docs; cd ../docs; 
	cd ../NEAT/; make doc; cd ../docs;
	cd ../../HyperNEAT-master/; make docs; cd ../Practica/docs;
	cd ../../opencv-2.4.13.3/build/; make doxygen; cd ../../Practica/docs;
	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	

MODI_raw_all:
	cd ../RobotLib; make docs;cd ../docs;
	cd ../NEAT/; make doc; cd ../docs;
	cd ../../HyperNEAT-master/; make docs; cd ../Practica/docs;
	cd ../../opencv-2.4.13.3/build/; make doxygen; cd ../../Practica/docs;
	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F2	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F3	
