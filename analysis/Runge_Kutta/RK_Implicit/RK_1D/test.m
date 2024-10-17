close all
clear all
format long
clc

a1 = [0 0 0 0 ;
    1/2 0 0 0 ;
    0 1/2 0 0 ;
    0 0 1 0];
b1 = [1/6 1/3 1/3 1/6];
c1 = [0 1/2 1/2 1];

x = x(a1,b1,c1,0.1,1,1)