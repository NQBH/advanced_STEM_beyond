function jacob = compute_jacobian(vertices, dervals_psi)
% Evaluate the Jacobian matrix of the geometric function at a given point
% Author: Nguyen Quan Ba Hong
% Date: 15/10/2018
% Last Update: 15/10/2018
% Inputs:
% + vertices: the coordinates of the main (in P_1) nodes of a triangle, size: 3x2
% + dervals_psi: the values of the derivatives of the geometric basis
% functions at the point hat(x)
% Output:
% + jacob: the value of Jacobian matrix of the geometric function F_K(hat(x))
% at the given point hat(x)

jacob = zeros(2); % Initialize
for k = 1:2
    for l = 1:2
        jacob(k,l) = dot(vertices(:,k), dervals_psi(:,l));
    end
end
