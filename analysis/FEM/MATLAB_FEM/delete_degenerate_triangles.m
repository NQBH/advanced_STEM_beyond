function mesh_out = delete_degenerate_triangles(mesh, tol)
% Delete all degenerate triangles in the mesh given. Define a "degenerate"
% triangle as a triangle whose the radius of its corresponding inscribed
% circle is less than some given tolerance, e.g. inscribed_radius < 1e-2
% Author: Nguyen Quan Ba Hong
% Date: 08/10/2018
% Last Update: 29/10/2018
% Input:
% + mesh: a mesh structure
% Output:
% + mesh_out: a mesh structure without degenerate triangles 

%% Classify Degenerate and Nondegenerate Triangles
triangles = []; % Initialize
for i = 1:size(mesh.triangles,1) % Loop on All Triangles of the Mesh Given
    % Compute the Inscribed Radius of the i-th Triangle
    [~, inscribed_radius] = inscribed_circle(mesh.coords(mesh.triangles(i,:),:));
    if (inscribed_radius > tol) 
         triangles = [triangles; mesh.triangles(i,:)];
    end
end

%% Create a New Mesh without Degenerate Triangles
mesh_out = mesh_new('', mesh.coords, triangles);
