clear all
close all
clc
format long

tic

%% Choose Regularization Parameters
alpha = 11; % First Regularization Parameter

%% Initials
n = 50;
test = 2;
x_0 = 0; % the point x in 1/fs:1/fs:1 needing observing (Require: x_obs*fs must be an integer)
tol = 1e-16;
N0 = 300; % Maximum loops
a = 0;
b = 5;
i = 1;

%% Bisection Loops
while (i <= N0)
    beta = a + (b-a)/2;
    [u_regu,grid] = ihcp(alpha,beta,x_0);
    if (abs(u_regu(n/2,n/2) - u(test,x_0,grid(n/2),grid(n/2))) < tol)
        i
        beta
        return
    end
    i = i + 1;
    if (abs(u_regu(n/2,n/2)) > abs(u(test,x_0,grid(n/2),grid(n/2))))
        a = beta;
    else
        b = beta;
    end
end

toc
