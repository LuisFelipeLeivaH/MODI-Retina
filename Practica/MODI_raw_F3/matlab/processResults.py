import os
import numpy as np
import matplotlib.pylab as plt

cgray = [0.3,0.3,0.3]
MODI_path = 'raw_F1'
graphs= 'graphs/'
scenes=['Scene1/', 'Scene2/']

# Makes sure the graphs foldier exists
if(not os.path.isdir(graphs+scenes[0])):
	os.makedirs(graphs+scenes[0])
if(not os.path.isdir(graphs+scenes[1])):
	os.makedirs(graphs+scenes[1])

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
		plt.axis([0, 30, -0.5, 2.5])

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
		plt.axis([0, 30, 0, 3])
	else:
		plt.subplot(111, facecolor='y') # creates a subplot with yellow background if not yet simulated
		plt.xlabel('Champion '+MODI_path + ': Not yet simulated')
	

	#plt.savefig(path+'graphs/championFitness_'+MODI_path+'.pdf', format='pdf', bbox_inches='tight')
#  graphs_all_p + scene + 'experimentFitness_comparison.pdf'
	plt.savefig(graphs + scene +'champions_plot.pdf', format='pdf', bbox_inches='tight')


# -------------------------------------------------------

