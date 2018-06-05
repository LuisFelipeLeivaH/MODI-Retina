cleandocs:
	@rm -f -R ./MODI_raw_F1
	@rm -f -R ./MODI_raw_F2
	@rm -f -R ./MODI_raw_F3
	@rm -f -R ./MODI_retina_F1
	@rm -f -R ./MODI_retina_F2
	@rm -f -R ./MODI_retina_F3
	cd ../RobotLib/; make cleandocs; cd ../docs 

MODI_all:
	cd ../RobotLib; make docs; cd ..;
	#@mkdir -p ./MODI_raw_F1
	pwd;
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

	#@cp -r latex ./doc
	#@rm -rf latex
	#@cp -r html ./doc
	#@rm -rf html

MODI_raw_F1:
	cd ../RobotLib; make docs; cd ..; 
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	

MODI_raw_all:
	cd ../RobotLib; make docs;cd ..;
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F1	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F2	
	@cd ../../doxygen_files; doxygen Doxyfile_MODI_raw_F3	