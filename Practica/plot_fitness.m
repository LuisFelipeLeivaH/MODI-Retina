%Fitness: (Generation,	Fitness Mean,	Fitness Stddesviation)

%Choose scene
SCENE='1'

%% Load data (for only Scene #SCENE)
path_champ_raw_F1 = fullfile('MODI_raw_F1', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')
path_champ_raw_F2 = fullfile('MODI_raw_F2', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')
path_champ_raw_F3 = fullfile('MODI_raw_F3', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')
path_champ_retina_F1 = fullfile('MODI_retina_F1', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')
path_champ_retina_F2 = fullfile('MODI_retina_F2', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')
path_champ_retina_F3 = fullfile('MODI_retina_F3', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'champions.txt')

path_fit_raw_F1 = fullfile('MODI_raw_F1', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')
path_fit_raw_F2 = fullfile('MODI_raw_F2', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')
path_fit_raw_F3 = fullfile('MODI_raw_F3', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')
path_fit_retina_F1 = fullfile('MODI_retina_F1', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')
path_fit_retina_F2 = fullfile('MODI_retina_F2', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')
path_fit_retina_F3 = fullfile('MODI_retina_F3', 'matlab', 'data', strcat('Scene', SCENE), 'simulation_files', 'fitness.txt')


if[exist(path_fit_raw_F1)]
    fit_raw_F1 = importdata(path_fit_raw_F1, '\t');
end

if[exist(path_fit_raw_F2)]
    fit_raw_F2 = importdata(path_fit_raw_F2, '\t');
end
if[exist(path_fit_raw_F3)]
    fit_raw_F3 = importdata(path_fit_raw_F3, '\t');
end
if[exist(path_fit_retina_F1)]
    fit_retina_F1 = importdata(path_fit_retina_F1, '\t');
end
if[exist(path_fit_retina_F2)]
    fit_retina_F1 = importdata(path_fit_retina_F2, '\t');
end
if[exist(path_fit_retina_F3)]
    fit_retina_F1 = importdata(path_fit_retina_F3, '\t');
end

if[exist(path_champ_raw_F1)]
    champ_raw_F1 = importdata(path_champ_raw_F1, '\t');
end
if[exist(path_champ_raw_F2)]
    champ_raw_F2 = importdata(path_champ_raw_F2, '\t');
end
if[exist(path_champ_raw_F3)]
    champ_raw_F3 = importdata(path_champ_raw_F3, '\t');
end
if[exist(path_champ_retina_F1)]
    champ_retina_F1 = importdata(path_champ_retina_F1, '\t');
end
if[exist(path_champ_retina_F2)]
    champ_retina_F2 = importdata(path_champ_retina_F2, '\t');
end
if[exist(path_champ_retina_F3)]
    champ_retina_F3 = importdata(path_champ_retina_F3, '\t');
end

%% Fitness Scene 1
figure;

subplot(2,3,1);
hold on, grid on;
if[exist(path_fit_raw_F1)]
    dst_pos = fit_raw_F1.data(:,2)+fit_raw_F1.data(:,3);
    dst_neg = fit_raw_F1.data(:,2)-fit_raw_F1.data(:,3);
    plot(fit_raw_F1.data(:,1),fit_raw_F1.data(:,2))
    plot(fit_raw_F1.data(:,1),dst_pos,'r-')
    plot(fit_raw_F1.data(:,1),dst_neg,'r-')
end
hold off;
title(strcat('Scene ', SCENE, ' Fitness RAW_{F1}'))
ylim([-0.5, 2.5])

subplot(2,3,4);
hold on, grid on;
if[exist(path_fit_retina_F1)]
    dst_pos = fit_retina_F1.data(:,2)+fit_retina_F1.data(:,3);
    dst_neg = fit_retina_F1.data(:,2)-fit_retina_F1.data(:,3);
    plot(fit_raw_F1.data(:,1),fit_retina_F1.data(:,2))
    plot(fit_raw_F1.data(:,1),dst_pos,'r-')
    plot(fit_raw_F1.data(:,1),dst_neg,'r-')
end
hold off;
title(strcat('Scene ', SCENE, ' Fitness RETINA_{F1}'))
ylim([-0.5, 2.5])

subplot(2,3,2);
hold on, grid on;
if[exist(path_fit_raw_F2)]
    dst_pos = fit_raw_F2.data(:,2)+fit_raw_F2.data(:,3);
    dst_neg = fit_raw_F2.data(:,2)-fit_raw_F2.data(:,3);
    plot(fit_raw_F2.data(:,1),fit_raw_F2.data(:,2))
    plot(fit_raw_F2.data(:,1),dst_pos,'r-')
    plot(fit_raw_F2.data(:,1),dst_neg,'r-')
end
hold off;
title(strcat('Scene ', SCENE, ' Fitness RAW_{F2}'))
ylim([-0.5, 2.5])

subplot(2,3,5);
hold on, grid on;
if[exist(path_fit_retina_F2)]
    dst_pos = fit_retina_F2.data(:,2)+fit_retina_F2.data(:,3);
    dst_neg = fit_retina_F2.data(:,2)-fit_retina_F2.data(:,3);
    plot(fit_raw_F1.data(:,1),fit_retina_F2.data(:,2))
    plot(fit_raw_F1.data(:,1),dst_pos,'r-')
    plot(fit_raw_F1.data(:,1),dst_neg,'r-')
end
hold off;
ylim([-0.5 2.5]);
title(strcat('Scene ', SCENE, ' Fitness RETINA_{F2}'))
ylim([-0.5, 2.5])

subplot(2,3,3);
hold on, grid on;
if[exist(path_fit_raw_F3)]
    dst_pos = fit_raw_F3.data(:,2)+fit_raw_F3.data(:,3);
    dst_neg = fit_raw_F3.data(:,2)-fit_raw_F3.data(:,3);
    plot(fit_raw_F3.data(:,1),fit_raw_F3.data(:,2))
    plot(fit_raw_F3.data(:,1),dst_pos,'r-')
    plot(fit_raw_F3.data(:,1),dst_neg,'r-')
end
hold off;
title(strcat('Scene ', SCENE, ' Fitness RAW_{F3}'))
ylim([-0.5, 2.5])

subplot(2,3,6);
hold on, grid on;
if[exist(path_fit_retina_F3)]
    dst_pos = fit_retina_F3.data(:,2)+fit_retina_F3.data(:,3);
    dst_neg = fit_retina_F3.data(:,2)-fit_retina_F3.data(:,3);
    plot(fit_raw_F1.data(:,1),fit_retina_F3.data(:,2))
    plot(fit_raw_F1.data(:,1),dst_pos,'r-')
    plot(fit_raw_F1.data(:,1),dst_neg,'r-')
end
hold off;
ylim([-0.5 2.5]);
title(strcat('Scene ', SCENE, ' Fitness RETINA_{F3}'))
ylim([-0.5, 2.5])

%% Champion scene #SCENE
figure;

subplot(2,3,1);
hold on, grid on;
if[exist(path_champ_raw_F1)]
    plot(champ_raw_F1.data(:,1),champ_raw_F1.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RAW_{F1}'))
ylim([0, 3])

subplot(2,3,4);
hold on, grid on;
if[exist(path_champ_raw_F1)]
    plot(champ_raw_F1.data(:,1),champ_retina_F1.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RETINA_{F1}'))
ylim([0, 3])

subplot(2,3,2);
hold on, grid on;
if[exist(path_champ_raw_F2)]
    plot(champ_raw_F2.data(:,1),champ_raw_F2.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RAW_{F2}'))
ylim([0, 3])

subplot(2,3,5);
hold on, grid on;
if[exist(path_champ_raw_F1)]
    plot(champ_raw_F1.data(:,1),champ_retina_F2.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RETINA_{F2}'))
ylim([0, 3])

subplot(2,3,3);
hold on, grid on;
if[exist(path_champ_raw_F3)]
    plot(champ_raw_F3.data(:,1),champ_raw_F3.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RAW_{F3}'))
ylim([0, 3])

subplot(2,3,6);
hold on, grid on;
if[exist(path_champ_raw_F1)]
    plot(champ_raw_F1.data(:,1),champ_retina_F3.data(:,3))
end
hold off;
title(strcat('Scene ', SCENE, ' Champion RETINA_{F3}'))
ylim([0, 3])