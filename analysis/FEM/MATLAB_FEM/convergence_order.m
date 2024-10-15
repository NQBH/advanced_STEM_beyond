function [] = convergence_order(mesh_geo, times, degree_FE)
% Calculate the numerical solution for different values of the
% discretization parameter h and plot the curves of the relatives errors
% for the euclidean and the infinity norms, with respect to h, in "loglog"
% scale
% (a) for the P_1 approximation
% (b) for the P_2 approximation
% Author: Nguyen Quan Ba Hong
% Date: 8/11/2018
% Last Update: 8/11/2018
% Inputs:
% + mesh_geo: a mesh structure defining the geometry, if degree_FE = 1,
% this mesh structure must be a P_1 mesh structure, if degree_FE = 2, it
% must be modified into a P_2 mesh structure
% + times: the number of times which we refine the mesh given
% + degree_FE: degree of the finite-element interpolation
% + Output: a plot of the curves of the relative errors for the euclidean
% and the infinity norms, with respect to h, in "loglog" scale

%% Initializations
h_max = 100; % Fixed Maximal Discretization Parameter
relative_error_euclidean = zeros(times + 1,1);
relative_error_infinity = zeros(times + 1,1);
number_mesh_point = zeros(times + 1,1);

% Solve the Neumann BVP for the Initial Mesh
[X, nodes] = solve_Neumann_BVP(mesh_geo, h_max, degree_FE);
% Compute the Number of Nodes ofthe Initial Mesh
number_mesh_point(1) = size(nodes,1); 
% Compute the Exact Solution on the Initial Mesh
U_ex = zeros(size(nodes,1),1); % Initialize
for i = 1:size(nodes,1)
    U_ex(i) = exact_solution(nodes(i,1), nodes(i,2));
end
% Compute the Relative Error for the Euclidean Norm
relative_error_euclidean(1) = norm(X - U_ex,2)/norm(U_ex,2);
% Compute the Relative Error for the infinity Norm
relative_error_infinity(1) = norm(X - U_ex,Inf)/norm(U_ex,Inf);

%% Main Loop
for i = 1:times % Refine the Inputted Mesh times Times
    mesh_geo = refine_mesh(mesh_geo); % Refine the Current Mesh
    [X, nodes] = solve_Neumann_BVP(mesh_geo, h_max, degree_FE);
    % Compute the Number of Nodes of the Current Mesh
    number_mesh_point(i+1) = size(nodes,1);
    % Compute the Exact Solution on the Initial Mesh
    U_ex = zeros(size(nodes,1),1); % Initialize
    for j = 1:size(nodes,1)
        U_ex(j) = exact_solution(nodes(j,1), nodes(j,2));
    end
    % Compute the Relative Error for the Euclidean Norm
    relative_error_euclidean(i+1) = norm(X - U_ex,2)/norm(U_ex,2);
    % Compute the Relative Error for the infinity Norm
    relative_error_infinity(i+1) = norm(X - U_ex,Inf)/norm(U_ex,Inf);
end

%% Plot the Relative Errors in the "loglog" Scale
figure
plot(log(number_mesh_point), -log(relative_error_euclidean), 'blue',...
     log(number_mesh_point), -log(relative_error_infinity), 'red',...
     log(number_mesh_point), log(number_mesh_point), 'green',...
     log(number_mesh_point), 2*log(number_mesh_point), 'black');
xlabel('Log(MeshPoint)');ylabel('-Log(Error)');
title('Relative Errors');
legend('Euclidean norm','infinity norm','y=x','y = 2x','Location','NorthEastOutside');
