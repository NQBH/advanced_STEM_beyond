function mesh_s = mesh_new(name, coords, triangles)
% define a new mesh_structure
% Author: G. Vial
% Date: 08/09/2010
% Last update: 22/09/11 -- E. Darrigrand
% usage: mesh_s = mesh_new(name,coords,triangles)
% input -
%    name : string
%    coords : (NbPts x 2) array
%    triangles : (NbTriangles x NbNodes) array
% output -
%    mesh_s : mesh structure

mesh_s = struct('name', name, 'coords', coords, 'triangles', triangles);
