function [triangle_number, max_edge_size] = find_worst_triangle(mesh)
% Determine the "worst" element of a given mesh, i.e., the element has the 
% longest edge in the mesh, and provide the length of that longest edge
% Author: Nguyen Quan Ba Hong
% Date: 29/10/2018
% Last Update: 29/10/2018
% Input:
% + mesh: a mesh structure
% Outputs:
% + triangle_number: Index of the "worst" element of the mesh given
% + max_edge_size: the length of the longest edge in the mesh given

%% Create the Tables edges & edges_triangles
[edges, edges_triangles] = build_edge_connectivity(mesh);

%% Compute the Lengths of All Edges in the Mesh Given
length_edges = zeros(size(edges,1),1);  % Initialize
for i = 1:size(edges,1) % Loop on All Edges of the Mesh Given
    % Compute the Length of the i-th Edge
    length_edges(i) = norm(mesh.coords(edges(i,1),:) - mesh.coords(edges(i,2),:));
end

%% Determine the Longest Edge and Its Index
[max_edge_size, edge_number] = max(length_edges);

%% Determine a Triangle Containing the Longest Edge
triangle_number = edges_triangles{edge_number}(1,1);
