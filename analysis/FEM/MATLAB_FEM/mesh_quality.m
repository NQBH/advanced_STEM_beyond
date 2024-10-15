function quality = mesh_quality(mesh)
% Compute the quality of a given mesh, defined as the largest roundness of the
% elements of that mesh
% Author: Nguyen Quan Ba Hong
% Date: 09/10/2018
% Last Update: 17/10/2018
% Inpute:
% + mesh: a mesh structure
% Output:
% + quality: the quality of the mesh given

%% Store the Roundness of All Triangles in the Mesh
sigma = zeros(size(mesh.triangles,1),1); % Initialize
for i = 1:size(mesh.triangles,1) % Loop on All Triangles of the Mesh
    % Compute the Roundness of i-th Triangle in the Mesh
    sigma(i) = roundness(mesh.coords(mesh.triangles(i,:),:)); 
end

%% Compute the Quality of the Given Mesh
quality = max(sigma);
