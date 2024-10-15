function [edges, edges_triangles] = build_edge_connectivity(mesh)
% Build the tables edges & edges_triangles of a mesh given
% Author: Nguyen Quan Ba Hong
% Date: 06/10/2018
% Last Update: 16/10/2018
% Input:
% + mesh: a P_1 mesh structure
% Outputs:
% + edges: edges(K,:) = numbers of the points that determining the edge
% numbered K
% + edges_triangles{K} = couples(element, local number of edge) for the
% elements which contain the edge numbered K

%% Build the Table edges
edges = []; % Initialize
for K = 1:size(mesh.triangles,1) % Loop on All Triangles of the Mesh Given
    temp = sort([mesh.triangles(K,[1,2]);
        mesh.triangles(K,[2,3]);
        mesh.triangles(K,[1,3])],2); % Read the 3 Edges of the K-th Triangle
    flag = ones(3,1); % flag = 0: Already Contained; flag = 1: Not Contained Yet
    for i = 1:3 % Loop on 3 Edges of the K-th Triangle
        for j = 1:size(edges,1)
            % Check if the edge considered is already in table edges or not
            if (edges(j,:) == temp(i,:)) % This Edge was Contained in edges
                flag(i) = 0; % Ignore this Edge
            end
        end
        if (flag(i) == 1)
            edges = [edges; temp(i,:)]; % Store the Desired Edge
        end
    end
end

%% Build Cell-Array edges_triangles
for i = 1:size(edges,1) % Loop on All the Edges
    edges_triangles{i} = []; % Initialize
    for j = 1:size(mesh.triangles,1) % Loop on the Triangles of the Mesh
        if (edges(i,:) == sort(mesh.triangles(j,[1,2])))
            edges_triangles{i} = [edges_triangles{i}; j,1]; % First Edge
        elseif (edges(i,:) == sort(mesh.triangles(j,[2,3])))
            edges_triangles{i} = [edges_triangles{i}; j,2]; % Second Edge
        elseif (edges(i,:) == sort(mesh.triangles(j,[1,3])))
            edges_triangles{i} = [edges_triangles{i}; j,3]; % Third Edge
        end
    end
end
