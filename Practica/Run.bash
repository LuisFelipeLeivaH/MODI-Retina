cd $1; cd bin
if [ $2 == T ]
	then
	./RIAR user_def GeneticEncoding1024 $3
	cd ..; make save; cd bin
	cd ..; mkdir -p "matlab/data/Scene${4}"; rm -rf  matlab/data/Scene${4}/*; cd bin
	cp -r ./simulation_files NEAT_organisms GeneticEncoding1024 raw_speeds.txt user_def ../matlab/data/Scene${4}

elif [ $2 == S ]
	then
	./Champion ./NEAT_organisms/Champion.txt $3
fi
cd ../..