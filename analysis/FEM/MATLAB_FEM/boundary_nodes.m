function boundary_nodes = boundary_nodes(mesh)
% Produce a table containing the coordinates of the nodes on the
% boundary of a given mesh
% Author: Nguyen Quan Ba Hong
% Date: 30/10/2018
% Last Update: 30/10/2018
% Input:
% + mesh: a mesh structure
% Output:
% + boundary_nodes: a table of size (the number of nodes on boundary)x2
% containing the coordinates of the nodes on the boundary of the mesh given

%% Create the Tables edges & edges_triangles
[edges, edges_triangles] = build_edge_connectivity(mesh);

%% Take All Boundary Nodes of the Mesh Given
boundary_nodes = []; % Initialize
for i = 1:size(mesh.coords,1) % Loop on All Nodes of the Given Mesh
    % Check if the Node is Interior or Not
    for j = 1:size(edges,1) % Loop on All Edges of the Given Mesh
        % Check if the Edge Contains the i-th Node or Not
        if (edges(j,1) == i || edges(j,2) == i) 
            if (size(edges_triangles{j},1) == 1) % This is a Boundary Edge
               boundary_nodes = [boundary_nodes; mesh.coords(i,:)]; 
               break
            end
        end
    end
end
