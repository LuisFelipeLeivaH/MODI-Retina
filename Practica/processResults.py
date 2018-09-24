import os
import numpy as np
import matplotlib.pylab as plt
from matplotlib.ticker import FuncFormatter
from matplotlib.backends.backend_pdf import PdfPages

cgray = [0.3,0.3,0.3]
scenes=['Scene1/', 'Scene2/']
graphs_all_p = 'docs/simulation_graphs/'
MODI_paths = ['raw_F1', 'raw_F2', 'raw_F3', 'raw_F4', 'raw_F5', 'raw_F6', 'retina_F1', 'retina_F2', 'retina_F3', 'retina_F4', 'retina_F5', 'retina_F6']
MODI_paths_os = ['raw_F1', 'raw_F2', 'raw_F3', 'retina_F1', 'retina_F2', 'retina_F3']
MODI_paths_fe = ['raw_F4', 'raw_F5', 'raw_F6', 'retina_F4', 'retina_F5', 'retina_F6']

# Makes sure the graphs foldier exists
if(not os.path.isdir(graphs_all_p+scenes[0])):
	os.makedirs(graphs_all_p+scenes[0])
if(not os.path.isdir(graphs_all_p+scenes[1])):
	os.makedirs(graphs_all_p+scenes[1])




#--------------------------------------------------------------------
# ------------      Fitness      ------------------------------------
#--------------------------------------------------------------------


# First we plot from F1 to F3

for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To find minimum and maximum values in y axis
	ul = -float('inf')
	ll = float('inf')
	for MODI_path in MODI_paths_os:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'fitness.txt')):	
			#print(path)
			fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,1]
			d_std = fit_raw[:,2]

			if(ul < max(mean_fit_raw + d_std)):
				ul = max(mean_fit_raw + d_std)

			if(ll > min(mean_fit_raw - d_std)):
				ll = min(mean_fit_raw - d_std)	

	# To generate the Fitness plots
	for MODI_path in MODI_paths_os:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'fitness.txt')):	
			#print(path)
			fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,1]
			d_std = fit_raw[:,2]

			# -------------------------------------------------------
			plt.subplot(2, 3, i)#int('25' + str(i)))
			plt.plot(fit_raw[:,0], mean_fit_raw , color='blue', label='Fitness ' + MODI_path, linewidth=2)
			plt.fill_between(fit_raw[:,0], mean_fit_raw - d_std, mean_fit_raw + d_std, color='blue', alpha=0.3)

			plt.legend(loc=2)
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Fitness ' + MODI_path)
			plt.grid(True)
			plt.axis([0, 30, ll*1.1, ul*1.15])

		else:
			plt.subplot(2, 3, i, facecolor='y')#int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Fitness '+MODI_path + ': Not yet simulated')
		i += 1
		
		#plt.savefig(path+'graphs/experimentFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene +'/' + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs_all_p + scene +'experimentFitness_comparison_F1-F3.pdf', format='pdf', bbox_inches='tight')
	i=1		# used as an auxiliary for subplotting

plt.close('all')
# Then we plot from F4 to F6

for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To find minimum and maximum values in y axis
	ul = -float('inf')
	ll = float('inf')
	for MODI_path in MODI_paths_fe:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'fitness.txt')):	
			fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,1]
			d_std = fit_raw[:,2]

			if(ul < max(mean_fit_raw + d_std)):
				ul = max(mean_fit_raw + d_std)

			if(ll > min(mean_fit_raw - d_std)):
				ll = min(mean_fit_raw - d_std)			

	# To generate the Fitness plots
	for MODI_path in MODI_paths_fe:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'fitness.txt')):	
			#print(path)
			fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,1]
			d_std = fit_raw[:,2]			

			# -------------------------------------------------------
			plt.subplot(2, 3, i)#int('25' + str(i)))
			plt.plot(fit_raw[:,0], mean_fit_raw , color='blue', label='Fitness ' + MODI_path, linewidth=2)
			plt.fill_between(fit_raw[:,0], mean_fit_raw - d_std, mean_fit_raw + d_std, color='blue', alpha=0.3)

			plt.legend(loc=2)
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Fitness ' + MODI_path)
			plt.grid(True)
			plt.axis([0, 30, ll*1.1, ul*1.15])

		else:
			plt.subplot(2, 3, i, facecolor='y')#int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Fitness '+MODI_path + ': Not yet simulated')
		i += 1
	
	#plt.savefig(path+'graphs/experimentFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene +'/' + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs_all_p + scene +'experimentFitness_comparison_F4-F6.pdf', format='pdf', bbox_inches='tight')
	i=1		# used as an auxiliary for subplotting

plt.close('all')


#--------------------------------------------------------------------
# ------------      Champion fitnesses per generation      ----------
#--------------------------------------------------------------------




for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To find minimum and maximum values in y axis
	ul = -float('inf')
	ll = float('inf')
	for MODI_path in MODI_paths_os:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'champions.txt')):	
			#print(path)
			fit_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,2]			

			if(ul < max(mean_fit_raw)):
				ul = max(mean_fit_raw)

			if(ll > min(mean_fit_raw)):
				ll = min(mean_fit_raw)	

	# To generate the Champion plots
	for MODI_path in MODI_paths_os:
		path = 'MODI_' + MODI_path + '/matlab/data/' + scene +'simulation_files/'		
		if(os.path.exists(path+'champions.txt')):	
			#print(path)		
			champ_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)  	
			plt.subplot(2, 3, i)#int('26' + str(i)))	  	
			plt.plot(champ_raw[:,0], champ_raw[:,2] , color='blue', label='Champion '+MODI_path, linewidth=2)

			plt.grid(True)
			plt.legend()
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Champion ' + MODI_path)
			plt.grid(True)
			plt.axis([0, 30, ll*1.1, ul*1.15])
		else:
			plt.subplot(2, 3, i, facecolor='y') #int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Champion '+MODI_path + ': Not yet simulated')
		i += 1

	plt.savefig(graphs_all_p + scene +'Champion_comparison_F1-F3.pdf', format='pdf', bbox_inches='tight')

#plt.show()
plt.close('all')


for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To find minimum and maximum values in y axis
	ul = -float('inf')
	ll = float('inf')
	for MODI_path in MODI_paths_fe:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'champions.txt')):	
			#print(path)
			fit_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,2]			

			if(ul < max(mean_fit_raw)):
				ul = max(mean_fit_raw)

			if(ll > min(mean_fit_raw)):
				ll = min(mean_fit_raw)	

	# To generate the Champion plots
	for MODI_path in MODI_paths_fe:
		path = 'MODI_' + MODI_path + '/matlab/data/' + scene +'simulation_files/'		
		if(os.path.exists(path+'champions.txt')):	
			#print(path)		
			champ_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)  	
			plt.subplot(2, 3, i)#int('26' + str(i)))	  	
			plt.plot(champ_raw[:,0], champ_raw[:,2] , color='blue', label='Champion '+MODI_path, linewidth=2)

			plt.grid(True)
			plt.legend()
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Champion ' + MODI_path)
			plt.grid(True)
			plt.axis([0, 30, ll*1.1, ul*1.15])
		else:
			plt.subplot(2, 3, i, facecolor='y') #int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Champion '+MODI_path + ': Not yet simulated')
		i += 1

	plt.savefig(graphs_all_p + scene +'Champion_comparison_F4-F6.pdf', format='pdf', bbox_inches='tight')

#plt.show()
plt.close('all')



#--------------------------------------------------------------------
# ------------      Champion activation functions      --------------
#--------------------------------------------------------------------




N = 5				# Number of activation functions
x = np.arange(N)
def identity(x, pos):
	return '%1.1f' % (x)

formatter = FuncFormatter(identity)

for scene in scenes:
	for MODI_path in MODI_paths:
		path = 'MODI_' + MODI_path + '/matlab/data/' + scene +'NEAT_organisms/'			
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
				if(MODI_path == 'raw_F6' or MODI_path == 'retina_F6'):
					ax.text(i-0.16, v + 0.05, str(v), color='blue', fontweight='bold')
				else:
					ax.text(i-0.16, v + 0.05, str(v), color='blue', fontweight='bold')

		else:
			#print 'File ' + path + 'Champion.txt' + ' does not yet exist'
			plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Champion '+MODI_path + ': Not yet simulated')

		plt.savefig(graphs_all_p + scene +'Champion_'+MODI_path+'_ActivationFunctions.pdf', format='pdf', bbox_inches='tight')

plt.close('all')