clearvars; clc; 

figure(1); clf; hold on
sgtitle('sampling frequency effects')

subplot(3,2,1); hold on
title('f = 1.2 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 1.2  ; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');

subplot(3,2,2); hold on
title('f = 1.8 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 1.8  ; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');

subplot(3,2,3); hold on
title('f = 2 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 2  ; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');

subplot(3,2,4); hold on
title('f = 2.2 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 2.2  ; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');

subplot(3,2,5); hold on
title('f = 2.4 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 2.4  ; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');

subplot(3,2,6); hold on
title('f = 8.2 f_m')
fplot(@(x) sin(x))
xlim([0,16*pi])
rate = 2*pi / 8.2; 
t = 0:rate:16*pi; 
y = sin(t); 
plot(t,y,'o');
