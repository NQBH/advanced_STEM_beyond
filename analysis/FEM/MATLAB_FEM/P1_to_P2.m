function mesh_P2 = P1_to_P2(mesh_P1)
% Build a P_2 mesh structure from a given P_1 mesh structure. The local
% numbering should follow the convention of Local numbering of the
% reference triangles P_2 as follows: the midpoints of the edges 1, 2, 3
% are labeled 4, 5, 6, respectively.
% Author: Nguyen Quan Ba Hong
% Date: 16/10/2018
% Last Update: 16/10/2018
% Input:
% + mesh_P1: a P_1-structured mesh
% Output:
% + mesh_P2: a P_2-structured mesh

%% Create the Table edges
[edges, ~] = build_edge_connectivity(mesh_P1);

%% Construct the Nodes coords of mesh_P2
coords = mesh_P1.coords; % Reuse the Nodes of mesh_P1
for i = 1:size(edges,1) % Loop on the Edges of mesh_P1
    % Add the Midpoint of i-th Edge of mesh_P1 to coords of mesh_P2
    coords = [coords; (coords(edges(i,1),:) + coords(edges(i,2),:))/2];
end

%% Construct Triangles of mesh_P2
triangles = zeros(size(mesh_P1.triangles,1),6);
triangles(:,[1,2,3]) = mesh_P1.triangles; % Reuse the Triangles of mesh_P1
for K = 1:size(mesh_P1.triangles,1) % Loop on All Triangles of mesh_P1
    for i = 1:size(edges,1) % Loop on All Edges of mesh_P1
        if (sort(mesh_P1.triangles(K,[1,2])) == edges(i,:)) % First Edge
            triangles(K,4) = size(mesh_P1.coords,1) + i; % First Midpoint
        elseif (sort(mesh_P1.triangles(K,[2,3])) == edges(i,:)) % Second Edge
            triangles(K,5) = size(mesh_P1.coords,1) + i; % Second Midpoint
        elseif (sort(mesh_P1.triangles(K,[1,3])) == edges(i,:)) % Third Edge
            triangles(K,6) = size(mesh_P1.coords,1) + i; % Third Midpoint
        end
    end
end

%% Create a P2-Structured Mesh
mesh_P2 = mesh_new('Mesh_P2', coords, triangles);
