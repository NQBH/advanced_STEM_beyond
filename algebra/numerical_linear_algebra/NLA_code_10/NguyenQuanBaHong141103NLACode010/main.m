clear all
close all
clc
format long

A = rand(100);
A = A'*A;
tic
R  = CF(A);
R'*R-A
% Test.
% R1 = chol(A) % chol built-in function.
norm(R'*R-A)
toc

