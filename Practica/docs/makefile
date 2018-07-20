cleandocs:
	@rm -f -R ./MODI_raw_F1
	@rm -f -R ./MODI_raw_F2
	@rm -f -R ./MODI_raw_F3
	@rm -f -R ./MODI_raw_F4
	@rm -f -R ./MODI_raw_F5
	@rm -f -R ./MODI_retina_F1
	@rm -f -R ./MODI_retina_F2
	@rm -f -R ./MODI_retina_F3
	@rm -f -R ./MODI_retina_F4
	@rm -f -R ./MODI_retina_F5
	cd ../RobotLib/; make cleandocs; cd ../docs 

MODI_all:
	cd ../RobotLib; make docs; cd ..;	
	pwd;
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F2	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F3
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F4
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F5	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F1
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F2
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F3
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F4
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_retina_F5	

MODI_raw_F1F4:
	cd ../RobotLib; make docs; cd ..; 
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F4	

MODI_raw_all:
	cd ../RobotLib; make docs;cd ..;
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F2	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F3
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F4
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F5	