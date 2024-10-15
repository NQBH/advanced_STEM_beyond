function boundary_edges = boundary_edges(mesh)
% Build the set of edges defining the boundary of a given mesh
% Author: Nguyen Quan Ba Hong
% Date: 17/10/2018
% Last Update: 17/10/2018
% Input:
% + mesh: a P_1 mesh structure
% Output:
% + boundary_edges: the set of edges defining the boundary of the mesh
% given

%% Construct the Tables edges & edges_triangles of the Given Mesh
[edges, edges_triangles] = build_edge_connectivity(mesh);

%% Determine the Boundary of the Given Mesh
boundary_edges = []; % Initialize
for i = 1:size(edges,1) % Loop on All Edges of the Mesh Given
    if (size(edges_triangles{i},1) == 1) % This is a Boundary Edge
        % Store this Boundary Edge
        boundary_edges = [boundary_edges; edges(i,:)]; 
    end
end
