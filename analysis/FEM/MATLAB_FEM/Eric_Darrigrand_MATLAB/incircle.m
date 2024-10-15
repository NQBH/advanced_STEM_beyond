function [incenter,inradius] = incircle(triangle_coor)
% Compute the inscribed circle data of a triangle given 
% by the coordinates of its vertices.
% Author: E.Darrigrand
% Date: 22/09/2011
% Last update: 22/09/2011
%
% usage: [incenter,inradius] = incircle(triangle_coor)
%
% input -
%   triangle_coor : 3x2 array containing the coordinates of the vertices of the triangle.  
% output - 
%   incenter : center of the inscribed circle
%   inradius : radius of the inscribed circle
%
A = triangle_coor(1,:);
B = triangle_coor(2,:);
C = triangle_coor(3,:);
AB = sqrt((B-A)*(B-A)'); %'
AC = sqrt((C-A)*(C-A)'); %'
BC = sqrt((C-B)*(C-B)'); %'
G = (1./(AB+AC+BC))*(BC*A+AC*B+AB*C);
incenter = G;
AG = sqrt((G-A)*(G-A)'); %'
vABAC = cross([B-A,0],[C-A,0]);
ABAC = sqrt(vABAC*vABAC'); %'
angleCAG = 0.5*asin(ABAC / (AB*AC));
inradius = AG * sin(angleCAG);

