function mesh_out = refine_mesh(mesh)
% Refine a mesh by adding the midpoints of all edges of the mesh given
% Author: Nguyen Quan Ba Hong
% Date: 06/10/2018
% Last Update: 08/10/2018
% Input: 
% + mesh: a P1 mesh structure
% Output:
% + mesh_out: a refined mesh

%% Create the Table edges for the Mesh Given
[edges, ~] = build_edge_connectivity(mesh);

%% Construct coords of mesh_P2
coords = mesh.coords; % Reuse all the Nodes of the Mesh Given
for i = 1:size(edges,1) % Loop on All Edges of the Mesh Given
    % Add the Midpoint of i-th Edge to the New Table coords
    coords = [coords; (coords(edges(i,1),:) + coords(edges(i,2),:))/2];
end

%% Construct the Table triangles for the New Mesh
triangles = []; % Initialize
for i = 1:size(mesh.triangles,1) % Loop on All Triangles of the Mesh Given
    for j = 1:size(edges,1) % Loop on All Edges of the Mesh Given
        if (edges(j,:) == sort([mesh.triangles(i,1), mesh.triangles(i,2)]))
            midpoint_edge1 = j + size(mesh.coords,1);
        end
        if (edges(j,:) == sort([mesh.triangles(i,2), mesh.triangles(i,3)]))
            midpoint_edge2 = j + size(mesh.coords,1);
        end
        if (edges(j,:) == sort([mesh.triangles(i,1), mesh.triangles(i,3)]))
            midpoint_edge3 = j + size(mesh.coords,1);
        end
    end
    triangles = [triangles; mesh.triangles(i,1),midpoint_edge1,midpoint_edge3;
        mesh.triangles(i,2),midpoint_edge1,midpoint_edge2;
        mesh.triangles(i,3),midpoint_edge2,midpoint_edge3;
        midpoint_edge1,midpoint_edge2,midpoint_edge3];
end

%% Create the Final Mesh
mesh_out = mesh_new('', coords, triangles);
