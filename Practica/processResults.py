import os
import numpy as np
import matplotlib.pylab as plt
from matplotlib.backends.backend_pdf import PdfPages

cgray = [0.3,0.3,0.3]
scenes=['Scene1/', 'Scene2/']
graphs_all_p = 'docs/simulation_graphs/'
MODI_paths = ['raw_F1', 'raw_F2', 'raw_F3', 'retina_F1', 'retina_F2', 'retina_F3']

# Makes sure the graphs foldier exists
if(not os.path.isdir(graphs_all_p+scenes[0])):
	os.makedirs(graphs_all_p+scenes[0])
if(not os.path.isdir(graphs_all_p+scenes[1])):
	os.makedirs(graphs_all_p+scenes[1])

#--------------------------------------------------------------------
# ------------      Fitness      ------------------------------------
#--------------------------------------------------------------------

for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To generate the Fitness plots
	for MODI_path in MODI_paths:
		path = 'MODI_' + MODI_path + '/matlab/data/'+scene+'simulation_files/'		
		if(os.path.exists(path+'fitness.txt')):			
			fit_raw = np.loadtxt(path+'fitness.txt', delimiter='\t', skiprows=1)	
			mean_fit_raw = fit_raw[:,1]
			d_std = fit_raw[:,2]

			# -------------------------------------------------------
			plt.subplot(int('23' + str(i)))
			plt.plot(fit_raw[:,0], mean_fit_raw , color='blue', label='Fitness ' + MODI_path, linewidth=2)
			plt.fill_between(fit_raw[:,0], mean_fit_raw - d_std, mean_fit_raw + d_std, color='blue', alpha=0.3)

			plt.legend(loc=2)
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Fitness ' + MODI_path)
			plt.grid(True)
			plt.axis([0, 30, -0.5, 2.5])

		else:
			plt.subplot(int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Fitness '+MODI_path + ': Not yet simulated')
		i += 1

		
		#plt.savefig(path+'graphs/experimentFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene +'/' + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs_all_p + scene +'experimentFitness_comparison.pdf', format='pdf', bbox_inches='tight')
	i=1		# used as an auxiliary for subplotting
#--------------------------------------------------------------------
# ------------      Champion      -----------------------------------
#--------------------------------------------------------------------

for scene in scenes:
	i=1		# used as an auxiliary for subplotting
	plt.figure(figsize=(14,8))

	# To generate the Champion plots
	for MODI_path in MODI_paths:
		path = 'MODI_' + MODI_path + '/matlab/data/' + scene +'simulation_files/'		
		if(os.path.exists(path+'champions.txt')):			
			champ_raw = np.loadtxt(path+'champions.txt', delimiter='\t', skiprows=1)  	
			plt.subplot(int('23' + str(i)))	  	
			plt.plot(champ_raw[:,0], champ_raw[:,2] , color='blue', label='Champion '+MODI_path, linewidth=2)

			plt.grid(True)
			plt.legend()
			plt.xlabel('Generation number')
			plt.ylabel('Fitness value')
			#plt.title('Champion ' + MODI_path)
			plt.axis([0, 30, 0, 3])
		else:
			plt.subplot(int('23' + str(i)), facecolor='y') # creates a subplot with yellow background if not yet simulated
			plt.xlabel('Champion '+MODI_path + ': Not yet simulated')
		i += 1

		#plt.savefig(path+'graphs/championFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
	#  graphs_all_p + scene + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs_all_p + scene +'experimentChampion_comparison.pdf', format='pdf', bbox_inches='tight')

#plt.show()
