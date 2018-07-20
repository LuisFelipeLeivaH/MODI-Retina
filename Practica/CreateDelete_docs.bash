#!/bin/bash

aux=0
echo "Do you wish to auto-generate the documentation? [Y/n]"
while : ; do
	read DOCS
	if [[ $DOCS = "Y" ]]; then
		aux=1
	elif [[ $DOCS = "n" ]]; then
		aux=2
	else
		aux=0
	fi

	if [[ $aux -eq 0 ]]; then
		echo "Please type Y (yes) or n (no)"
	else
		break
	fi
	
done 

if [ $DOCS = "Y" ]
	then
		cd ./docs
		echo "Do you wish to create documentation only for MODI_raw_F1 and MODI_raw_F4, for all MODI_raw's or do you prefer full documentation? (type the number please)"
		while : ; do
			echo -e ' \t ' 1.- MODI_raw_F1 and MODI_raw_F4
			echo -e ' \t ' 2.- MODI_raw_\*
			echo -e ' \t ' 3.- Full documentation
			read OPTION
		
			if [ $OPTION == 1 ]
			then
				make MODI_raw_F1F4
				break

			elif [ $OPTION == 2 ]
			then
				make MODI_raw_all
				break

			elif [ $OPTION == 3 ]
			then
				make MODI_all
				break

			else
				echo "Please type a number (1, 2, or 3)"
			fi
		done
		echo "Docs have been successfuly created."
		cd ..
elif [[ $DOCS = "n" ]]; then
	echo "Do you wish to clean all docs? [Y/n]"
	while : ; do
		read OPTION
		if [[ $OPTION = "Y" ]]; then
			cd ./docs; make cleandocs; cd ..;
			echo "Docs have been successfuly deleted."
			break
		elif [[ $OPTION = "n" ]]; then
			echo "Docs niether created nor deleted."
			break
		else
			echo "Please type Y (yes) or n (no)"
		fi
	done
fi