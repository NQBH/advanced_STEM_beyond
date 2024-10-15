function mesh_plot(mesh_s,show_numbers)
% plot a mesh
% Author:G.Vial
% Date: 08/09/2010
% Last update: 14/09/10
%
% usage: mesh_plot(mesh_s,show_numbers)
%
% input -
%   mesh_s: mesh structure
%   show_numbers: boolean(true if numbers are displayed)
%
triangles = getfield(mesh_s,'triangles');
coords = getfield(mesh_s,'coords');
nb_triangles = size(triangles,1);
name = getfield(mesh_s,'name');
%
trimesh(triangles(:,1:3),coords(:,1),coords(:,2),'Color','b');
%
if (show_numbers)
   % offset for numbering
   offset = max(max(coords))/100;
   for k = 1:nb_triangles
      triangle = triangles(k,:);
      coord = coords(triangle,:);
      % display global numbers
      for v = 1:size(triangle,2)
         text(coord(v,1)+offset,coord(v,2)-offset,num2str(triangle(v)));
      end
      % display triangle number
      G = mean(coord(1:3,:));
      text(G(1),G(2),num2str(k),'Color','red');
   end
end
%
% axis and title
axis equal
axis off
title(name,'FontWeight','bold')
xlabel('x')
ylabel('y')
