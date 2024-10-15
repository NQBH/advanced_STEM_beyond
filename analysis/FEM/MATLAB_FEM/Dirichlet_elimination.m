function [Aout, Bout] = Dirichlet_elimination(Ain, Bin, boundary_nodes)
% An elimination procedure, which consists of - for a given node I on the
% Dirichlet boundary - vanishing the I-th component of the right hand side
% and all entries of the I-th line of the matrix except the diagonal one. 
% Author: Nguyen Quan Ba Hong
% Date: 17/10/2018
% Last Update: 17/10/2018
% Inputs:
% + Ain: the assembled matrix
% + Bin: the assembled vector
% + boundary_nodes: the table entry boundary_nodes contains the global
% numbers of the nodes on the Dirichlet boundary
% Outputs:
% + Aout: the assembled matrix after the Dirichlet elimination procedure
% + Bout: the assembled vector after the Dirichlet elimination procedure

for i = 1:size(boundary_nodes,1)
    % Vanish the i-th component of the right hand side
    Bin(i) = 0;
    % Vanish all the entries of the i-th line of the matrix except the diagonal one
    temp = Ain(i,i);
    Ain(i,:) = zeros(1,size(Ain,1)); % Vanish all entries of A(i,:)
    Ain(i,i) = temp; % Except the diagonal entry A(i,i)    
end
Aout = Ain;
Bout = Bin;

