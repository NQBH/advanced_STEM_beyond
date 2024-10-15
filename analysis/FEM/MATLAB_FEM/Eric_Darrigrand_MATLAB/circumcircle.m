function [circumcenter,circumradius] = circumcircle(triangle_coor)
% Compute the circumscribed circle data of a triangle given 
% by the coordinates of its vertices.
% Author: E.Darrigrand
% Date: 22/09/2011
% Last update: 22/09/2011
%
% usage: [circumcenter,circumradius] = circumcircle(triangle_coor)
%
% input -
%   triangle_coor : 3x2 array containing the coordinates of the vertices of the triangle.  
% output - 
%   circumcenter : center of the circumscribed circle
%   circumradius : radius of the circumscribed circle
%
a = triangle_coor(2,1) - triangle_coor(1,1);
b = triangle_coor(2,2) - triangle_coor(1,2);
c = triangle_coor(3,1) - triangle_coor(1,1);
d = triangle_coor(3,2) - triangle_coor(1,2);
e = 0.5 * (triangle_coor(2,1) + triangle_coor(1,1));
f = 0.5 * (triangle_coor(2,2) + triangle_coor(1,2));
g = 0.5 * (triangle_coor(3,1) + triangle_coor(1,1));
h = 0.5 * (triangle_coor(3,2) + triangle_coor(1,2));
%
alpha = a*e + b*f;
beta = c*g + d*h;
%
% With the notations above, the center has the coordinates (x,y) given below:
%
y = (alpha*c - a*beta)/(b*c - a*d);
if (abs(a)>abs(c))
   x = (alpha - b*y)/a;
else
   x = (beta - d*y)/c;
end
circumcenter = [x,y];
% 
% The radius is then the distance between the center and a vertex:
%
vect = [x,y]-triangle_coor(1,:);
circumradius = sqrt(vect*vect');

