clear all
close all
clc
format long

tic

%% A. AUTOMATIC MESHES FOR POLYGONAL STRUCTURES

%% A.1. Structure of a Mesh

%% Initialize a mesh
% coords = [0,0; 1,0; 1,1; 0,1; .5,.5];
% triangles = [1 2 5; 2 3 5; 5 4 3;1 5 4];
% my_mesh = mesh_new('', coords, triangles);
% co = getfield(my_mesh, 'coords');
% tr = getfield(my_mesh, 'triangles');
% my_mesh.name = 'Example of a mesh';

%% EXERCISE A.1
% [edges, edges_triangles] = build_edge_connectivity(my_mesh);

%% Display the Tables edges and edges_triangles
% edges
% for i = 1:size(edges,1)
%    edges_triangles{i}
% end

%% EXERCISE A.2
% mesh_P2 = P1_to_P2(my_mesh);
% figure(1)
% mesh_plot(mesh_P2,1)

%% Refine Mesh
% mesh_P2 = P1_to_P2(my_mesh);
% for i = 1:5
%     my_mesh = P1_to_P2(my_mesh);
%     figure(i)
%     mesh_plot(my_mesh,0)
%     axis equal
% end

%% Triangulation de Delaunay
% triangles = delaunay(coords(:,1),coords(:,2));
% my_mesh = mesh_new('',coords,triangles);
% my_mesh.name = 'Triangulation of Delaunay';

%% EXERCISE 3
% my_mesh = P1_to_P2(my_mesh);
% my_mesh = P1_to_P2(my_mesh);
% my_mesh = P1_to_P2(my_mesh);
% my_mesh = P1_to_P2(my_mesh);

% my_mesh.name = 'Circumscribed Circles of Triangles';
% figure
% hold on
% mesh_plot(my_mesh,0)
% for i = 1:size(my_mesh.triangles,1)
%     [center, radius] = circumcircle(my_mesh.coords(my_mesh.triangles(i,:),:));
%     t = linspace(0,2*pi);
%     x = center(1) + radius*cos(t);
%     y = center(2) + radius*sin(t);
%     plot(x,y);
% end
% axis equal

%% EXERCISE 4
% [triangle_number, max_edge_size] = find_worst_triangle(my_mesh);
% boundary_vertices = [0,0;3,1;4,4;2,7;-2,8;-4,6;-5,5;-4,1];
% mesh_size = 2;
% mesh_out = mesh_by_barycenters(boundary_vertices, mesh_size);
% % Plot
% figure(2)
% mesh_plot(mesh_out,0);
% 
% %% EXERCISE 5
% % quality = mesh_quality(mesh_out)
% 
% %% EXERCISE 6
% mesh_out = mesh_optimize(mesh_out);
% figure(3)
% mesh_plot(mesh_out,0);

%-------------------------------------------------------------------------
%% B. FINTE-ELEMENT CALCULATION

%% B.1. Quadrature Formulas

%% EXERCISE B.1
% [points, weights] = quadrature(2)

%% EXERCISE B.2
% xh = [1,1]; % Arbitrary Point
% k = 1; % k = 1 or 2
% [vals, dervals] = shape_fcts(xh,k)

%% EXERCISE B.3
% vertices = [0,0; 1,0; 0,1];
% x = [0,0];
% [~, dervals_psi] = shape_fcts(x,1);
% jacob = compute_jacobian(vertices, dervals_psi)
%
%% EXERCISE B.4
% coords = [0,0;0.5,0;1,0;0,0.5;0.5,0.5;1,0.5;0,1;0.5,1;1,1];
% triangles = [1,2,4;2,5,4;2,3,5;3,6,5;4,5,7;5,8,7;5,6,8;6,9,8];
% mesh_geo = mesh_new('', coords, triangles);
% mesh_geo = refine_mesh(mesh_geo);
% mesh_geo = refine_mesh(mesh_geo);
% mesh_geo = refine_mesh(mesh_geo);
% mesh_geo = refine_mesh(mesh_geo);
% mesh_geo = refine_mesh(mesh_geo);
% mesh_plot(mesh_geo,1); % Plot the Current Mesh

% degree_FE = 2; % Degree of Finite Elements
% if (degree_FE == 2)
%     mesh_geo = P1_to_P2(mesh_geo);
% end
% 
% M =  assemble_matrix('Id', 'Id', 'f_one', mesh_geo, degree_FE, 2);
% R1 = assemble_matrix('D1', 'D1', 'f_one', mesh_geo, degree_FE, 1);
% R2 = assemble_matrix('D2', 'D2', 'f_one', mesh_geo, degree_FE, 1);
% R = R1 + R2
% A = M + R;
% b = assemble_vector('Id', 'source_function', mesh_geo, degree_FE, 2);
% % mesh_plot(mesh_geo,1)

%% B.6. Essential Conditions (Optinal)
%% Dirichlet Elimination
% boundarynodes = boundary_nodes(mesh_geo);
% [A, b] = Dirichlet_elimination(A, b, boundarynodes);

%% B.7. Resolution and Post-Treatment
% % Solve the Linear System Ax = b
% X = A\b;
% % Plot the solution X at the nodes of the mesh
% figure(3)
% trisurf(mesh_geo.triangles, mesh_geo.coords(:,1), mesh_geo.coords(:,2), X);
% colorbar

%% Plot the Exact Solution 
% t = 0:0.1:1;
% [x,y] = meshgrid(t);
% u = exact_solution(x,y);
% figure(4)
% surf(x,y,u)
% colorbar

%--------------------------------------------------------------------------
%% C. EXAMINATION - NUMERICAL VALIDATION

%% C.1. Validation of the Assembling Procedure
%% A Given Mesh
coords = [0,0;0.5,0;1,0;0,0.5;0.5,0.5;1,0.5;0,1;0.5,1;1,1];
triangles = [1,2,4;2,5,4;2,3,5;3,6,5;4,5,7;5,8,7;5,6,8;6,9,8];
mesh_geo = mesh_new('', coords, triangles);

%% Compute the Mass Matrix 
% % Use the P_1 nodal quadrature formula
% M =  assemble_matrix('Id', 'Id', 'f_one', mesh_geo, 1, 1)
% % Use the P_3 nodal quadrature formula
% M =  assemble_matrix('Id', 'Id', 'f_one', mesh_geo, 1, 2)

%% Compute the Stiffness Matrix
% R1 = assemble_matrix('D1', 'D1', 'f_one', mesh_geo, 1, 1);
% R2 = assemble_matrix('D2', 'D2', 'f_one', mesh_geo, 1, 1);
% R = R1 + R2

%% C.2. Validation of the Convergence Order of the Finite-Element Method
%% Problem 2.1
mesh_geo = refine_mesh(mesh_geo);
mesh_geo = refine_mesh(mesh_geo);
mesh_geo = refine_mesh(mesh_geo);
mesh_geo = refine_mesh(mesh_geo);
mesh_geo = refine_mesh(mesh_geo);
[X, nodes] = solve_Neumann_BVP(mesh_geo, 100, 2);
mesh_geo = P1_to_P2(mesh_geo);
figure
trisurf(mesh_geo.triangles, mesh_geo.coords(:,1), mesh_geo.coords(:,2), X);
colorbar

%% Problem 2.2
% convergence_order(mesh_geo, 4, 2);

toc
