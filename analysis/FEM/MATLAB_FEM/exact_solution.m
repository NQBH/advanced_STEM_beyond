function exact_sol = exact_solution(x,y)
% The exact solution is given by u(x) = cos(pi*x)*cos(pi*y)
% Input:
% + x: a 2x1 or 1x2 vector
% Output:
% + exact_sol: the value of the exact solution at the point x, i.e. 
% u(x,y) = cos(pi*x)*cos(pi*y)

exact_sol = cos(pi*x).*cos(pi*y);
