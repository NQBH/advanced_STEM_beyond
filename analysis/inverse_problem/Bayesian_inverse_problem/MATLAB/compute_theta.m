clear all
close all
clc
format short

% syms m x;
% % m = 1/2;
% f = (4*m^2 - 1)^2*x^2 - 2*(16*m^6 - 4*m^4 + 4*m^2 - 1)*x + (4*m^4 + 1)^2;
% % df = diff(f,x,1);
% % A = simplify((8*m^2 - 8*m^4 + 32*m^6 - 2)/(2*(4*m^2 - 1)^2))
% % factor(A)
% simplify(subs(f,x,m^2))
% simplify(subs(f,x,0))

% syms alpha zeta tau t y;
% f = exp(1i*(zeta*y + t*sqrt(alpha^4 - zeta^4))) - exp(1i*(zeta*y - t*sqrt(alpha^4 - zeta^4)));
% Chi = simplify(1/(2*pi*1i*t)*int(f,zeta,-alpha,alpha))

% syms x a;
% a = 1;
% f = x^(1/2)*(1-x)^(-3/4);
% simplify(int(f,x,0,1))

% syms n l;
% f = (log(n+1+sqrt((n+1)^2-1)))^3 - (log(n+sqrt(n^2-1)))^3;
% limit(f,n,Inf)

% syms t x y; % l = 1
% u = simplify(cos(pi*t/4)*cos(pi*y/5)*exp((2-x)^2/2-(t^2+y^2)/20))
% varphi = simplify(subs(u,x,1))
% psi = simplify(subs(diff(u,x,1),x,1))
% f = simplify(diff(u,t,1) - diff(u,x,2) - diff(u,y,2))
% factor(f)

syms n x beta;
% beta = 1;
% gamma = log(n + (n^2 - 1)^(1/2));
 
% t = 1:10;
% subs(gamma,n,t)
% g = (log(x+1+sqrt((x+1)^2-1)))^3 - (log(x+sqrt(x^2-1)))^3;
% limit(g,x,Inf)
% Dg = simplify(diff(g,x,1))
 
% h = (log(x+1+sqrt((x+1)^2-1)))^2*sqrt(x^2-1) - (log(x+sqrt(x^2-1)))^2*sqrt((x+1)^2-1);
% Dh = simplify(diff(h,x,1))
beta = 1;
Alpha = (log((n+1)/beta + sqrt((n+1)^2/beta^2-1)))^3 - (log(n/beta + sqrt(n^2/beta^2-1)))^3;
symsum(n^2/(n+1)^2*Alpha,n,1,Inf)

