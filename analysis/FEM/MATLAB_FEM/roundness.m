function sigma = roundness(triangle_coor)
% Compute the roundness of a triangle, which is given by the ratio between
% the radii of the circumscribed and the inscribed circles
% Author: Nguyen Quan Ba Hong
% Date: 09/10/2018
% Last Update: 17/10/2018
% Input:
% + triangle_coor: is of size 3x2, gives the coordinates of three vertices
% of a triangle
% Output:
% + sigma: the roundness of the triangle given

%% Compute the Radius of the Circumscribed Circle of the Triangle 
[~, circumradius] = circumcircle(triangle_coor);

%% Compute the Radius of the Inscribed Circle of the Triangle
[~, inscribed_radius] = inscribed_circle(triangle_coor);

%% Compute the Roundness of the Triangle
sigma = circumradius/inscribed_radius;
