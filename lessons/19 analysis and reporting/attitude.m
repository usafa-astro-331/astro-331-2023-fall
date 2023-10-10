%% instructions
% 1 time only: 
% - import data to the workspace using the import data wizard
%   (save only data from a single (good) run)
% - save data from workspace to file with this command
%   save('attitude.mat', 'ATTITUDE'); 
%
% now you can load the data fresh with each script run
% and manipulate as much as you want 

clearvars; clc; 

load('attitude.mat');



xmax = max(ATTITUDE.magxuT); 
xmin = min(ATTITUDE.magxuT); 
xavg = (xmax+xmin)/2; 
xrange = xmax - xmin;

ATTITUDE.magxuT = ATTITUDE.magxuT - xavg;
ATTITUDE.magxuT = ATTITUDE.magxuT/(xrange/2);

ymax = max(ATTITUDE.magyuT); 
ymin = min(ATTITUDE.magyuT); 
yavg = (ymax+ymin)/2; 
yrange = ymax - ymin;

ATTITUDE.magyuT = ATTITUDE.magyuT - yavg;
ATTITUDE.magyuT = ATTITUDE.magyuT/(yrange/2);

heading = atan2d(ATTITUDE.magxuT, ATTITUDE.magyuT); 


figure(1); clf;
subplot(2,1,1)
yyaxis left
hold on

plot(ATTITUDE.timems/1000, ATTITUDE.magxuT); 
plot(ATTITUDE.timems/1000, ATTITUDE.magyuT); 
ylabel('magnetometer, uT')

legend('magx','magy', 'Location','northwest')


yyaxis right
plot(ATTITUDE.timems/1000,heading)

xlabel('time, s'); 
ylabel('heading, deg')

subplot(2,1,2)

yyaxis left
plot(ATTITUDE.timems/1000,ATTITUDE.gyrzdps)

xlabel('time, s')
ylabel('gyrz, deg/s')

yyaxis right
ATTITUDE.wheelRPM = -ATTITUDE.wheelRPM;
plot(ATTITUDE.timems/1000,ATTITUDE.wheelRPM)
ylabel('wheel speed, RPM')
