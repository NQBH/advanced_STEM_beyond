function mesh_out = mesh_by_barycenters(boundary_vertices, mesh_size)
% Build the mesh according to the following strategy:
% 1) For the initialization of the process: consider the triangulation
% T_0 obtained from a subdivision of the polygonal boundary of the domain
% of computation. This subdivison would be set of segments of size around
% mesh_size/2, where mesh_size is the requested size for the elements of the
% mesh.
% 2) Principle: Consider a triangulation T_n given at a step n, determine
% the "worst" triangle (i.e., of greatest edge), denote G its
% iso-barycenter. The new triangulation T_{n+1} is built by the insert of G
% into the set of points of T_n
% Author: Nguyen Quan Ba Hong
% Date: 08/10/2018
% Last Update: 29/10/2018
% Inputs:
% + boundary_vertices: vector which gives the coordinates of the
% vertices of the polygonal boundary of the computational domain
% + mesh_size: a scalar which specify the required maximal size for the
% elements of the output mesh
% Output:
% + mesh_out: the mesh built according to the described strategy, from a
% subdivision of the boundary of the domain of computation

%% Initialization of the Process: Zeroth Triangulation
coords = boundary_vertices; % Initialzie
for i = 1:size(boundary_vertices,1)-1 % Loop on All Non-Last Boundary Edges
    % Compute the Length of the i-th Boundary Edge
    length = norm(boundary_vertices(i,:) - boundary_vertices(i+1,:));
    loop = 2*ceil(length/mesh_size); % Number of Points for Partitioning
    for j = 1:loop-1
        % Equally-Spaced Partition of the i-the Boundary Edge
        coords = [coords; (loop-j)/loop*boundary_vertices(i,:) ...
            + j/loop*boundary_vertices(i+1,:)];
    end
end
i = i+1; % For the Last Boundary Edge
% Compute the Length of the Last Boundary Edge
length = norm(boundary_vertices(i,:) - boundary_vertices(1,:));
loop = 2*ceil(length/mesh_size); % Number of Points for Partitioning
for j = 1:loop-1
    % Equally-Spaced Partition of the Last Boundary Edge
    coords = [coords; (loop-j)/loop*boundary_vertices(i,:) ...
        + j/loop*boundary_vertices(1,:)];
end

%% Perform Delaunay Triangulation of the New Table coords
triangles = delaunay(coords(:,1), coords(:,2));

%% Modify the Triangulation by Adding Iso-Barycenter
tol = 1e-2; % Tolerence for the criteria of degenerate triangles
while 1
    mesh_out = mesh_new('', coords, triangles); % Update Mesh Structure
    mesh_out = delete_degenerate_triangles(mesh_out, tol);
    % Find the Worst Element and Its Radius in the Current Mesh
    [triangle_number, max_edge_size] = find_worst_triangle(mesh_out);
    if (max_edge_size <= mesh_size)  % Stopping Criteria
        break % the Current Mesh Fulfills the Requirements on Size
    end
    % Add Iso-barycenter of the Worst Triangle to the Mesh
    coords = [coords; 1/3*sum(coords(mesh_out.triangles(triangle_number,:),:))];
    triangles = delaunay(coords(:,1), coords(:,2));
end
