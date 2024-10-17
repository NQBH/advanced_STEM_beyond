clear all
close all
clc
format long

ep=0.0000000000000000000000000000000001;
syms x;
% % n=1 -------------------------------------------
% f=x*sin(1/(x+ep));
% hold on
% t=-0.2:0.001:0.2;
% plot(t,subs(f,t),'g')
% plot(t,subs(diff(f),t),'b')
% print -djpeg90 hinh0.jpg

% % n=2 -------------------------------------------
% f=x^2*sin(1/(x+ep));
% hold on
% t=-1:0.001:1;
% plot(t,subs(f,t),'g')
% plot(t,subs(diff(f),t),'b')
% print -djpeg90 hinh1.jpg

% % n=3 -------------------------------------------
% f=x^3*sin(1/(x+ep));
% hold on
% t=-0.2:0.001:0.2;
% plot(t,subs(f,t),'g')
% plot(t,subs(diff(f),t),'b')
% print -djpeg90 hinh2.jpg
% figure
% plot(t,subs(diff(f,x,2),t),'r')
% print -djpeg90 hinh3.jpg

% n=4 -------------------------------------------
f=x^4*sin(1/(x+ep));
hold on
t=-0.2:0.001:0.2;
plot(t,subs(f,t),'g')
plot(t,subs(diff(f),t),'b')
print -djpeg90 hinh4.jpg
figure
plot(t,subs(diff(f,x,2),t),'r')
print -djpeg90 hinh5.jpg

