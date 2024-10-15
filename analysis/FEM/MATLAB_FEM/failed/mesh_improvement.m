function mesh_out = mesh_improvement(mesh_in, mesh_size)
% Optimize a mesh by inserting the center of circumscribed circle instead
% of its iso-barycenter (except if it is outside of the domain, in that
% case, insert the midpoint of the largest edge)
% elements
% Author: Nguyen Quan Ba Hong
% Date: 11/10/2018
% Last Update: 11/10/2018

%% Initialize
A = [1, 2, 3]; % Use to Index Edge in a Triangle
coords = mesh_in.coords;
triangles = mesh_in.triangles;

%% Modify the Triangulation by Adding Circumcenter/Midpoints of the Largest Edge
while 1
    mesh_out = mesh_new('',coords,triangles);
    [edges, edges_triangles] = build_edge_connectivity(mesh_out);
    [triangle_number, ~, max_edge_size] = find_worst_triangle(mesh_out);
    % Stopping Criteria
    if (max_edge_size < mesh_size)
        break
    end
    triangle_coor = coords(triangles(triangle_number,:),:);
    % Compute Edges of the Worst Triangle
    a = norm(triangle_coor(2,:) - triangle_coor(3,:));
    b = norm(triangle_coor(3,:) - triangle_coor(1,:));
    c = norm(triangle_coor(1,:) - triangle_coor(2,:));
    [max_edge, index_max_edge] = max([a,b,c]);
    % Check if the i-th Triangle is Obtuse/Right or not
    if (2*max_edge^2 >= sum([a,b,c].^2)) % For Obtuse & Right Triangles
        temp = find(A ~= index_max_edge);
        % Update Coords
        coords = [coords; (triangle_coor(temp(1),:) + triangle_coor(temp(2),:))/2];
        % Update Triangles First Time
        triangles = [triangles; size(coords,1), triangles(triangle_number, [temp(1),index_max_edge]);
            size(coords,1), triangles(triangle_number, temp(2)), triangles(triangle_number, index_max_edge)];
        % Find Another Triangle Shared this Largest Edge
        for i = 1:size(edges,1)
            if (edges_triangles{i}(1,:) == [triangle_number, index_max_edge])
                temp2 = find(A ~= edges_triangles{i}(2,2));
                triangles = [triangles; triangles(edges_triangles{i}(2,1),[edges_triangles{i}(2,2),temp2(1)]), sizes(coords,1);
                    triangles(edges_triangles{i}(2,1),[edges_triangles{i}(2,2),temp2(2)]), sizes(coords,1)];
                triangles(edges_triangles{i}(2,1)) = [];
            end
            if (edges_triangles{i}(2,:) == [triangle_number, index_max_edge])
                temp2 = find(A ~= edges_triangles{i}(1,2));
                triangles = [triangles; triangles(edges_triangles{i}(1,1),[edges_triangles{i}(1,2),temp2(1)]), sizes(coords,1);
                    triangles(edges_triangles{i}(1,1),[edges_triangles{i}(1,2),temp2(2)]), sizes(coords,1)];
                triangles(edges_triangles{i}(1,1)) = [];
            end
        end
    else % For Acute Triangles
        [circumcenter, ~] = circumcircle(triangle_coor);
        % Update Coords
        coords = [coords; circumcenter];
        % Update Triangles
        triangles = [triangles; triangles(triangle_number,1), triangles(triangle_number,2), size(coords,1);
            triangles(triangle_number,2), triangles(triangle_number,3), size(coords,1);
            triangles(triangle_number,3), triangles(triangle_number,1), size(coords,1)];
        triangles(triangle_number,:) = []; % Delete the Worst Triangle
    end
end

%% Create Final Mesh
mesh_out = mesh_new('',coords,triangles);
