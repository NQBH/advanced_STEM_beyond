function [points, weights] = quadrature(number)
% Define the following two quadrature formulas to calculate an integral over
% the reference element
% number = 1: a nodal formula which is exact for all P_1 functions
% number = 2: a nodal formula which is exact for all P_3 functions by using
% the nodes of a P_2 interpolation plus the iso-barycenter of the triangle
% Author: Nguyen Quan Ba Hong
% Date: 12/10/2018
% Last Update: 12/10/2018
% Input:
% + number: take values 1 or 2, indicate which nodal formula will be used
% Outputs:
% + points: corresponding nodes in the reference element used for
% the nodal formula chosen
% + weights: corresponding weights used for the nodal formula chosen

if (number == 1) % P_1 Quadrature Formula
    points = [1,0; 0,1; 0,0]; % Nodes
    weights = [1/6; 1/6; 1/6]; % Weights
elseif (number == 2) % P_3 Quadrature Formula
    points = [0,0; 1,0; 0,1; .5,0; .5,.5; 0,.5; 1/3,1/3]; % Nodes
    weights = [1/40; 1/40; 1/40; 1/15; 1/15; 1/15; 9/40]; % Weights
else
    disp('Invalid Input');
end
