function f = source_function(x)
% The source function is given by f = - Laplacian(u) + u, where u is the
% exact solution
% Input:
% + x: a 2x1 or 1x2 vector
% Output:
% + f: the value of the source function at the point x, i.e. 
% f(x1,x2) = (2*pi^2 + 1)*cos(pi*x1)*cos(pi*x2)

f = (2*pi^2 + 1)*cos(pi*x(1))*cos(pi*x(2)); 
