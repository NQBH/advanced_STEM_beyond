clear all
close all
clc
format long

tic

l = 1; % x in [0,l]
L = -10;
R = 10;

%% Choose Regularization Parameters
alpha = 11; % First Regularization Parameter

%% Initials
m = 20; % Number of Gauss-Legendre Quadrature's Nodes
test = 2; % Key Test
n = 50; % Sampling Frequency
x_0 = -0.5; % the point x_0 in l/n:l/n:l needing observing (Require: x_0*n must be an integer)

%% Subs
if (L == 0)
    grid = R/n:R/n:R; % Plots
elseif (R == 0)
    grid = L:-L/n:L/n; % Plots
else
    grid = linspace(L,R,n);
end
[Y,T] = meshgrid(grid); % Plots

ratio = 0.1; %% >> Adjust this value << %%
tol = 1e-16; % Tolerance
N0 = 300; % Maximum Loops
a = 0;
b = 3;
i = 1;
direction = -1; % -1: down, +1: up
beta = b;

%% Exact Solution u(x,y,t)
u_exact = u(test,x_0,Y,T)';

%% Initials
RMSE_u_regu = 100;

%% Main Loop
while (i <= N0)
    beta = beta + direction*(b-a)*ratio;
    [u_regu,~] = ihcp(alpha,beta,x_0);
    
    temp_u_regu = RMSE_u_regu;
    RMSE_u_regu = 1/n*norm(u_regu - u_exact,'fro');
    
    %% Choose Here: u_regu or Du_regu
    i = i + 1;
    if (RMSE_u_regu > temp_u_regu)
        direction = - direction;
        if (direction == -1)
            a = beta;
        else
            b = beta;
        end
    else
        if (direction == -1)
            b = beta;
        else
            a = beta;
        end
    end
end
beta
RMSE_u_regu

toc
