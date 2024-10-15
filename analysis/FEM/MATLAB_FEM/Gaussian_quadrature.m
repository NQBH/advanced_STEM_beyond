function [points, weights] = Gaussian_quadrature(number)
% Define some Gaussian quadrature formulas to calculate an integral over
% the reference triangle
% Author: Nguyen Quan Ba Hong
% Date: 7/11/2018
% Last Update: 7/11/2018
% Input:
% + number: take values 1, 2, 3 or 4, indicate which Gaussian quadrature
% formula will be used
% Outputs:
% + points: the corresponding Gaussian quadrature nodes in the reference
% element used for the Gaussian quadrature formula chosen
% + weights: the corresponding Gaussian quadrature weights used for the
% Gaussian quadrature formula chosen

switch number
    case 1
        weights = 1;
        points = [1/3 1/3];
    case 2
        weights = [1/3 1/3 1/3];
        points = [1/6 1/6;
            2/3 1/6;
            1/6 2/3];
    case 3
        weights = [-27/48 25/48 25/48 25/48];
        points = [1/3 1/3;
            0.2 0.2;
            0.6 0.2;
            0.2 0.6];
    case 4
        weights = [0.223381589678011
            0.223381589678011
            0.223381589678011
            0.109951743655322
            0.109951743655322
            0.109951743655322];
        points = [0.445948490915965 0.445948490915965;
            0.445948490915965 0.108103018168070;
            0.108103018168070 0.445948490915965;
            0.091576213509771 0.091576213509771;
            0.091576213509771 0.816847572980459;
            0.816847572980459 0.091576213509771];
    otherwise
        error('Invalid Input')
end
