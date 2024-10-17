function f_mean=f_apx(x,i,k);

 % Midpoint rule
 if k == 1
f_mean = (x(i+1)-x(i))*f((x(i)+x(i+1))/2.0);
 end
%  Trepozoidal rule 
if k == 2
f_mean = (x(i+1)-x(i))/2*(f(x(i))+f(x(i+1))); 
end
% Simson's rule 
if k ==3
x_m = (x(i+1)+x(i))/2;
f_mean = (x(i+1)-x(i))/6*(f(x(i))+4*f(x_m)+f(x(i+1))); 
end
% Simson's 3/8 rule 
if k == 4
x_m1 = (x(i+1)+2*x(i))/3;
x_m2 = (2*x(i+1)+x(i))/3;
f_mean = (x(i+1)-x(i))/8*(f(x(i))+3*f(x_m1)+3*f(x_m2)+f(x(i+1))); 
end
% Boole's rule
if k == 5
x_m1 = (x(i+1)+3*x(i))/4;
x_m2 = (x(i+1)+x(i))/2;
x_m3 = (3*x(i+1)+x(i))/4;
f_mean = (x(i+1)-x(i))/90*(7*f(x(i))+32*f(x_m1)+12*f(x_m2)+32*f(x_m3)+7*f(x(i+1))); 
end