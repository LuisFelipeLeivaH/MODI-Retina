cd $1; cd bin
if [ $2 == T ]
	then
	if [[ $5 == 6 || $5 == 12 ]]; then
		./RIAR hyperneat_config.json user_def GeneticEncoding1024 $3
		cd ..; make save; cd bin
		cd ..; mkdir -p "matlab/data/Scene${4}"; rm -rf  matlab/data/Scene${4}/*; cd bin
		cp -r ./simulation_files NEAT_organisms GeneticEncoding1024 raw_speeds.txt user_def HyperNeat_conf_files hyperneat_config.json "../matlab/data/Scene${4}"
	else
		./RIAR user_def GeneticEncoding1024 $3
		cd ..; make save; cd bin
		cd ..; mkdir -p "matlab/data/Scene${4}"; rm -rf  matlab/data/Scene${4}/*; cd bin
		cp -r ./simulation_files NEAT_organisms GeneticEncoding1024 raw_speeds.txt user_def "../matlab/data/Scene${4}"
	fi	
		
# Fix Champion
elif [ $2 == S ]
	then	
	if [[ $5 == 6 || $5 == 12 ]]; then	
		./Champion "../matlab/data/Scene${4}/hyperneat_config.json" "../matlab/data/Scene${4}/NEAT_organisms/Champion.txt" $3
	else
		./Champion "../matlab/data/Scene${4}/NEAT_organisms/Champion.txt" $3
	fi
fi
cd ../..
