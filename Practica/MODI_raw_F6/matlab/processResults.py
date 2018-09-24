import os
import numpy as np
import matplotlib.pylab as plt
from matplotlib.ticker import FuncFormatter

cgray = [0.3,0.3,0.3]
MODI_path = 'raw_F6'
graphs= 'graphs/'
scenes=['Scene1/', 'Scene2/']

# Makes sure the graphs foldier exists
if(not os.path.isdir(graphs+scenes[0])):
	os.makedirs(graphs+scenes[0])
if(not os.path.isdir(graphs+scenes[1])):
	os.makedirs(graphs+scenes[1])


#--------------------------------------------------------------------

for scene in scenes:
	plt.figure(figsize=(14,8))
	path = 'data/'+scene
	if(os.path.exists(path+'raw_speeds.txt')):			
		fit_raw = np.loadtxt(path+'raw_speeds.txt', delimiter='\t', skiprows=1)	
		speed_left_raw = fit_raw[:,0]
		speed_right_raw = fit_raw[:,1]

		plt.subplot(2, 1, 1)
		plt.hist(speed_left_raw, bins = 100)
		plt.title('Histogram of raw speeds')
		plt.ylabel('Left Wheel Speed')
		plt.grid(True)

		plt.subplot(2, 1, 2)
		plt.hist(speed_right_raw, bins = 100)		
		plt.ylabel('Right Wheel Speed')		
		plt.grid(True)		

	else:
		plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
		plt.xlabel('Speeds '+MODI_path + ': Not yet simulated')

		
		#plt.savefig(path+'graphs/experimentFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene +'/' + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs + scene +'raw_speeds_histogram.pdf', format='pdf', bbox_inches='tight')


#--------------------------------------------------------------------

for scene in scenes:
	plt.figure(figsize=(14,8))
	path = 'data/'+scene+'simulation_files/'
	if(os.path.exists(path+'fitness.txt')):			
		fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
		mean_fit_raw = fit_raw[:,1]
		d_std = fit_raw[:,2]

		# -------------------------------------------------------
		plt.plot(fit_raw[:,0], mean_fit_raw , color='blue', label='Fitness ' + MODI_path, linewidth=2)
		plt.fill_between(fit_raw[:,0], mean_fit_raw - d_std, mean_fit_raw + d_std, color='blue', alpha=0.3)

		plt.legend(loc=2)
		plt.xlabel('Generation number')
		plt.ylabel('Fitness value')
		#plt.title('Fitness ' + MODI_path)
		plt.grid(True)
		#plt.axis([0, 30, -0.5, 2.5])

	else:
		plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
		plt.xlabel('Fitness '+MODI_path + ': Not yet simulated')

		
		#plt.savefig(path+'graphs/experimentFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene +'/' + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs + scene +'fitness_plot.pdf', format='pdf', bbox_inches='tight')

#--------------------------------------------------------------------
# ------------      Champion      -----------------------------------
#--------------------------------------------------------------------

for scene in scenes:	
	plt.figure(figsize=(14,8))	
	path = 'data/' + scene +'simulation_files/'		
	if(os.path.exists(path+'champions.txt')):			
		champ_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)  				
		plt.plot(champ_raw[:,0], champ_raw[:,2] , color='blue', label='Champion ' + MODI_path, linewidth=2)

		plt.grid(True)
		plt.legend()
		plt.xlabel('Generation number')
		plt.ylabel('Fitness value')
		#plt.title('Champion ' + MODI_path)
		#plt.axis([0, 30, 0, 3])
	else:
		plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
		plt.xlabel('Champion '+MODI_path + ': Not yet simulated')
	

	#plt.savefig(path+'graphs/championFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
#  graphs_all_p + scene + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs + scene +'champions_plot.pdf', format='pdf', bbox_inches='tight')


# -------------------------------------------------------

#--------------------------------------------------------------------
# ------------      Champion activation functions      --------------
#--------------------------------------------------------------------




N = 5				# Number of activation functions
x = np.arange(N)
def identity(x, pos):
	return '%1.1f' % (x)

formatter = FuncFormatter(identity)

for scene in scenes:
	path = 'data/' + scene + 'NEAT_organisms/'	
	if(os.path.exists(path+'Champion.txt')):			

		state='init'																#  Used for reading the Champion
		ran_f = {'gaussian': 0, 'sigmoid': 0, 'sin': 0, 'cos': 0, 'identity': 0}	# random functions to be counted
		Champion = open(path+'Champion.txt', 'r')

		for line in Champion:
			values=line.strip().split(':')

			# state machine for reading the genetic file
			if(values[0].replace('"', '' ) == "Genetic_Encoding"):
				state="Genetic_Encoding"					
			elif(values[0].replace('"', '') == "connection_genes"):
				state = "connection_genes"					

			# Reads and counts the random function
			if(state == "Genetic_Encoding"):
				if(len(values) == 6):
					fn = values[5].replace('"', '').replace('},','').replace(' ', '')
					if fn in ran_f:
						ran_f[fn] += 1

		Champion.close()

		val = [ran_f['gaussian'], ran_f['sigmoid'], ran_f['sin'], ran_f['cos'], ran_f['identity']]

		fig, ax = plt.subplots()
		ax.yaxis.set_major_formatter(formatter)
		plt.bar(x, val)
		plt.xticks(x, ('gaussian', 'sigmoid', 'sin', 'cos', 'identity'))
		ax.set_ylabel('Number of random functions')
		ax.set_title('Type of activation functions in Champion_' + MODI_path)

		for i, v in enumerate(val):
			ax.text(i-0.16, v + 3, str(v), color='blue', fontweight='bold')

	else:
		#print 'File ' + path + 'Champion.txt' + ' does not yet exist'
		plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
		plt.xlabel('Champion '+MODI_path + ': Not yet simulated')

	plt.savefig(graphs + scene +'Champion_'+MODI_path+'_ActivationFunctions.pdf', format='pdf', bbox_inches='tight')

