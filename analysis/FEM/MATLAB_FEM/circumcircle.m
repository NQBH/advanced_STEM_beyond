function [circumcenter, circumradius] = circumcircle(triangle_coor)
% Compute the center of the circumscribed circle and its radius, for a
% triangle given through the coordinates of its vertices
% Author: Nguyen Quan Ba Hong
% Date: 06/10/2018
% Last Update: 16/10/2018
% Input:
% + triangle_coor: is of size 3x2, gives the coordinates of three vertices
% of a triangle
% Outputs:
% + circumcenter: the center of the circumscribed circle of that triangle
% + circumradius: the radius of the circumscribed circle of that triangle

%% Compute the Area of the Triangle
S = polyarea(triangle_coor(:,1), triangle_coor(:,2));

%% Compute the Length of Edges of the Triangle
a = norm(triangle_coor(2,:) - triangle_coor(3,:)); % Length of edge BC
b = norm(triangle_coor(3,:) - triangle_coor(1,:)); % Length of edge CA
c = norm(triangle_coor(1,:) - triangle_coor(2,:)); % Length of edge AB

%% Alternative Way to Compute the Area of the Triangle
% S = 1/4*sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b)); % Heron's Formula

%% Compute the Circumradius
circumradius = 1/4*a*b*c/S;

%% Compute the Coordinates of Circumcenter
temp = [a^2*(b^2 + c^2 - a^2), b^2*(c^2 + a^2 - b^2), c^2*(a^2 + b^2 - c^2)];
circumcenter = temp(1)*triangle_coor(1,:) + temp(2)*triangle_coor(2,:) ...
    + temp(3)*triangle_coor(3,:);
circumcenter = circumcenter/sum(temp);
