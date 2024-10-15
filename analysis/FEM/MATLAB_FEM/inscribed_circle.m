function [inscribed_center, inscribed_radius] = inscribed_circle(triangle_coor)
% Compute the center & the radius of the inscribed circle of a triangle whose
% coordinates of its vertices are given
% Author: Nguyen Quan Ba Hong
% Date: 09/10/2018
% Last Update: 17/10/2018
% Input:
% + triangle_coor: is of size 3x2, gives the coordinates of three vertices
% of a triangle
% Outputs:
% + inscribed_center: the center of the inscribed circle of that triangle
% + inscribed_radius: the radius of the inscribed circle of that triangle

%% Compute the Area of the Triangle
S = polyarea(triangle_coor(:,1), triangle_coor(:,2));

%% Compute the Length of Edges of the Triangle
a = norm(triangle_coor(2,:) - triangle_coor(3,:)); % Length of edge BC
b = norm(triangle_coor(3,:) - triangle_coor(1,:)); % Length of edge CA
c = norm(triangle_coor(1,:) - triangle_coor(2,:)); % Length of edge AB

%% Alternative Way to Compute Area of the Triangle
% S = 1/4*sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b)); % Heron's formula

%% Compute Inscribed Radius of the Triangle
inscribed_radius = 2*S/(a+b+c);

%% Compute Coordinates of Circumcenter
inscribed_center = 1/(a+b+c)*(a*triangle_coor(1,:) + b*triangle_coor(2,:) ...
    + c*triangle_coor(3,:));
