EXPERIMENTOPC=(MODI_raw_F1 MODI_raw_F2 MODI_raw_F3 MODI_raw_F4 MODI_raw_F5 MODI_raw_F6 MODI_retina_F1 MODI_retina_F2 MODI_retina_F3 MODI_retina_F4 MODI_retina_F5 MODI_retina_F6)

echo Escriba el numero del experimento que desea realizar
echo Opciones:
echo -e ' \t ' 1.- MODI_raw_F1
echo -e ' \t ' 2.- MODI_raw_F2
echo -e ' \t ' 3.- MODI_raw_F3
echo -e ' \t ' 4.- MODI_raw_F4
echo -e ' \t ' 5.- MODI_raw_F5
echo -e ' \t ' 6.- MODI_raw_F6
echo -e ' \t ' 7.- MODI_retina_F1
echo -e ' \t ' 8.- MODI_retina_F2
echo -e ' \t ' 9.- MODI_retina_F3
echo -e ' \t ' 10.- MODI_retina_F4
echo -e ' \t ' 11.- MODI_retina_F5
echo -e ' \t ' 12.- MODI_retina_F6
read EXPERIMENT
NUM=$EXPERIMENT
EXPERIMENT=${EXPERIMENTOPC[$((EXPERIMENT - 1))]}

echo Seleccione la escena a usar '('1 ó 2')':
read SCENE

PORT=19996

if [ -d V-REP* ]
	then	
	check_port=$(netstat -an | grep $PORT) 
	until [ ${#check_port} == 0 ]
	do
		PORT=$(( PORT + 1 ))
		check_port=$(netstat -an | grep $PORT) 
	done

	if [[ ($NUM -ge 4 && $NUM -le 6) || ($NUM -ge 10 || $NUM -le 12) ]]; then
		TTTN="../Maze_Scene"$SCENE".ttt"
	else
		TTTN="../Scene"$SCENE"_FINAL.ttt"
	fi
	

	cd V-REP*
	chmod 755 MultiVrep.sh; 
	PIDS=$(bash ./MultiVrep.sh $PORT 1 $TTTN &)
	cd ..
	sleep 2	
	#vrep=$(pgrep -n vrep)
else
	echo ERROR: No existe la carpeta que contiene al simulador V-REP
	echo V-REP puede ser descargado desde 'http://www.coppeliarobotics.com/downloads.html'
	exit
fi

echo Escriba T para realizar un entrenamiento o S para mostrar el campeon:
read TAREA

if [ $TAREA == T ]
	then	
	bash Run.bash $EXPERIMENT $TAREA $PORT $SCENE $NUM

elif [ $TAREA == S ]
	then
	cd $EXPERIMENT	
	if [ -f "./matlab/data/Scene${SCENE}/NEAT_organisms/Champion.txt" ]
		then
		cd ..
		bash Run.bash $EXPERIMENT $TAREA $PORT $SCENE $NUM
	else
		echo ERROR: No existe el archivo Champion.txt
		cd ..
		exit
	fi
else
	echo ERROR: La instrucción no es correcta.
fi

sleep 2

kill -9 $PIDS

