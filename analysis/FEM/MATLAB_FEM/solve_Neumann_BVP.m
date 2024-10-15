function [X, nodes] = solve_Neumann_BVP(mesh_geo, h, degree_FE)
% Solve the problem: -Laplacian(u) + u = f with the homogeneous Neumann
% boundary condition, on a domain described geometrically by mesh_geo, by 
% application of the finite-element method (isoparametric P_1 or P_2). This
% function builds the mesh (P_1 or P_2) according to the discretization
% parameter h, then assemblies the matrix of the variational approximation,
% and finally solves the linear system.
% Author: Nguyen Quan Ba Hong
% Date: 8/11/2018
% Last Update: 8/11/2018
% Inputs:
% + mesh_geo: a mesh structure defining the geometry, if degree_FE = 1,
% this mesh structure must be a P_1 mesh structure, if degree_FE = 2, it
% must be modified into a P_2 mesh structure 
% + h: discretization parameter of the mesh
% + degree_FE: degree of the finite-element interpolation
% Outputs:
% + X: a vector which contains the approximation of the exact solution at
% the nodes of the mesh
% + nodes: the coordinates of the nodes of the built mesh 

%% Refine the Mesh Given
while 1
    % Compute the Mesh Size of the Current Mesh
    [~, max_edge_size] = find_worst_triangle(mesh_geo);
    if (max_edge_size <= h) % Stopping Criteria
        break % The Current Mesh is Fine Enough
    end
    mesh_geo = refine_mesh(mesh_geo); % Refine the Current Mesh
end

%% Choose Mesh Structure According to the Degree of the FE Interpolation
if (degree_FE == 2) % The FE Interpolation of Second Order
    mesh_geo = P1_to_P2(mesh_geo); % Modify mesh_geo into P_2 Mesh Structure
end

%% Assembling Procedures
% Compute the Mass Matrix
M =  assemble_matrix('Id', 'Id', 'f_one', mesh_geo, degree_FE, 2);
% Compute the Stiffness Matrix
R1 = assemble_matrix('D1', 'D1', 'f_one', mesh_geo, degree_FE, 1);
R2 = assemble_matrix('D2', 'D2', 'f_one', mesh_geo, degree_FE, 1);
% Assembly the Finite-Element Matrix
A = M + R1 + R2;
% Assembly the Finite-Element Right Hand Side Vector
b = assemble_vector('Id', 'source_function', mesh_geo, degree_FE, 2);

%% Resolution
X = A\b; % Solve the Linear System Ax = b
nodes = mesh_geo.coords; % the Nodes of the Current Mesh
