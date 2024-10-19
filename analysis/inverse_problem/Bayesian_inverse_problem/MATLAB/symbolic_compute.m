clear all
close all
clc
format long

syms x y t;
l = 1; % x in [0,l]

%% Exact Solutions
% u1 = exp((l+1-x)^2-y^2-t^2)
u1 = sin(pi/4*(y+2))*cos(pi/5*t)*exp((x-2)^2/2 - (y^2+t^2)/20);

%% Elements of the Smoothness Profile
D1u1 = simplify(diff(u1,x,1))
D2u1 = simplify(diff(u1,x,2))
D3u1 = simplify(diff(u1,x,3))
D4u1 = simplify(diff(u1,x,4))

%% Data Functions phi(y,t) = u(0,y,t)
phi1 = simplify(subs(u1,x,l))

%% Data Function psi(y,t) = u_x(0,y,t)
psi1 = simplify(subs(diff(u1,x,1),x,l))

%% Source Functions f(x,y,t) = (u_t-u_xx-u_yy)(x,y,t)
f1 = simplify(diff(u1,t,1)-diff(u1,x,2)-diff(u1,y,2))
D1f1 = simplify(diff(f1,x,1))
D2f2 = simplify(diff(f1,x,2))


