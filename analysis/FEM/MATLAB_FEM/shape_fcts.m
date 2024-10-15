function [vals, dervals] = shape_fcts(xh,k)
% Evaluate the nodal basis functions P_k (k = 1,2) of the reference element
% at a given point
% Author: Nguyen Quan Ba Hong
% Date: 12/10/2018
% Last Update: 12/10/2018
% Inputs:
% + xh: the point where we want to evaluate the functions
% + k: the degree of the finite element, k = 1 or 2
% Outputs:
% + vals: a table of the values of the basis functions at the point xh, size:
% NbRefNodes x 1
% + dervals: a table of the values of the corresponding derivatives in both
% directions, size: NbRefNodes x 2

if (k == 1) % First-Order Finite Element
    vals = [xh(1); xh(2); 1 - xh(1) - xh(2)]; % Values of Nodal Basis Functions P_1
    dervals = [1,0; 0,1; -1,-1]; % Derivatives of Nodal Basis Function P_1
elseif (k == 2) % Second-Order Finite Element
    [a, b] = shape_fcts(xh, 1); % Reuse the Nodal Basis Functions P_1
    vals = a.*(2*a - 1); % First 3 Nodal Basis Functions P_2
    % Add 3 Nodal Basis Functions P_2
    vals = [vals; 4*a(1)*a(2); 4*a(2)*a(3); 4*a(3)*a(1)];
    % Derivatives of Nodal Basis Functions P_2
    dervals = [(4*a(1) - 1)*b(1,:); (4*a(2) - 1)*b(2,:);
        (4*a(3) - 1)*b(3,:); 4*(a(2)*b(1,:) + a(1)*b(2,:));
        4*(a(2)*b(3,:) + a(3)*b(2,:)); 4*(a(3)*b(1,:) + a(1)*b(3,:))];
else
    disp('Invalid Input');
end
