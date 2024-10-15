function mesh_out = mesh_optimize(mesh_in)
% Optimize a mesh by the following strategy: Each interior point of the
% mesh (i.e. not on the boundary) is replaced by the iso-barycenter of its
% neighbors
% Author: Nguyen Quan Ba Hong
% Date: 08/10/2018
% Last Update: 17/10/2018
% Input:
% + mesh_in: a mesh structure needing improving the quality
% Output: 
% + mesh_out: optimized mesh structure

%% Reuse All the Nodes on the Boundary of the Mesh Given
boundarynodes = boundary_nodes(mesh_in); % Find All the Boundary Nodes
coords = boundarynodes; % Initialize

%% Add Iso-Barycenters of All Triangles of the Mesh Given
for i = 1:size(mesh_in.triangles,1) % Loop on All Triangles of the Mesh Given
    coords = [coords; 1/3*sum(mesh_in.coords(mesh_in.triangles(i,:),:))];
end

%% Create the Final Mesh
triangles = delaunay(coords(:,1), coords(:,2)); % Delaunay Triangulation
mesh = mesh_new('', coords, triangles);
mesh_out = delete_degenerate_triangles(mesh, 1e-2); 
