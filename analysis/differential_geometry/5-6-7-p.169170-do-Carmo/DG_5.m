clear all
close all
format short
clc

% syms u v E F G e f g x
% x = [u - u^3/3 + u*v^2,
%      v - v^3/3 + v*u^2,
%      u^2 - v^2];
%  
% xu = simplify(diff(x,u));
% xv = simplify(diff(x,v));
% 
% % E = simplify(dot(xu,xu));
% % F = simplify(dot(xu,xv));
% % G = simplify(dot(xv,xv));
% 
% xuxv = simplify(cross(xu,xv));
% 
% xuu = simplify(diff(x,u,2));
% xuv = simplify(diff(x,u,v));
% xvv = simplify(diff(x,v,2));
% 
% gg = [E F;
%      F G];
% 
% hh = [e f;
%      f g];
%  
% L = hh*inv(gg);
% simplify(L);
% K = simplify(det(L));
% H = simplify(trace(L)/2);
% d = simplify(sqrt(H^2 - K));
% 
% simplify(H^2*(E*G- F^2)^2 - K*(E*G- F^2))
% D = (E^2*g^2 - 4*E*F*f*g + 2*E*G*e*g + 4*F^2*f^2 - 4*F*G*e*f + G^2*e^2)...
%     - 4*(F^2*f^2 - e*g*F^2 - E*G*f^2 + E*G*e*g);

% syms u v E F G e f g x phi phi1 psi1
 
% xu = [-phi*sin(u), phi*cos(u),0];
% xv = [phi1*cos(u), phi1*sin(u),psi1];
% 
% xuxv = simplify(cross(xu,xv));

% f = sqrt(1-x^2)/x
% int(f,1,x)
% g = sqrt(1-x^2)
% diff(g,x)
% simplify(-x/(1 - x^2)^(1/2) - (-1)/(x*(1-x^2)^(1/2)))

% Xu=[-v*sin(u)
%     v*cos(u)
%     0]
% Xv=[cos(u)
%     sin(u)
%     (1 - v^2)^(1/2)/v]
% XuXv = simplify(cross(Xu,Xv))
% latex(XuXv)

% simplify(dot(Xu,Xv))
% 
% N = [(1 - v^2)^(1/2)*cos(u)
%      (1 - v^2)^(1/2)*sin(u)
%      -v]
% 
% Xuu = simplify(diff(Xu,u))
% Xuv = simplify(diff(Xu,v))
% Xvv = simplify(diff(Xv,v))
% 
% simplify(N'*Xuu)

% syms a  b c1 c2 d1 d2 x y z v u
% A = [c1 1;
%      d1 1]
% b = [c2 ; d2]
% x = A\b

C = 0.5;
a = -acosh(1/C);
b = acosh(1/C);

x= a:0.005:b;
n=length(x);
y=C*sinh(x);
z=zeros(1,n);
fun=@(t) sqrt(1-C^2*cosh(t).^2);
for i=1:n
    z(i)=integral(fun,0,x(i));
end
fig=figure;
set(fig, 'PaperSize', [5 6]);
plot(y,z)
axis equal
% titlename = sprintf('C = %.1f',C);
% title(titlename);
filename=sprintf('7c_2.pdf');
orient(fig,'landscape');
fig.PaperPositionMode = 'auto';
saveas(fig,filename);
fprintf(filename);
fprintf('\n');

% C = 0.5;
% a = -asin(1/C);
% b = asin(1/C);
% 
% x= a:0.005:b;
% n=length(x);
% y=C*cos(x);
% z=zeros(1,n);
% fun=@(t) sqrt(1-C^2*sin(t).^2);
% for i=1:n
%     z(i)=integral(fun,0,x(i));
% end
% fig=figure;
% set(fig, 'PaperSize', [5 6]);
% plot(y,z)
% axis equal
% % titlename = sprintf('C = %.1f',C);
% % title(titlename);
% filename=sprintf('7b_l1.pdf');
% orient(fig,'landscape');
% fig.PaperPositionMode = 'auto';
% saveas(fig,filename);
% fprintf(filename);
% fprintf('\n');
