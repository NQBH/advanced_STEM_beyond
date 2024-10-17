function x3 = x3(a,b,c,h,t,y)
F=@(k) [f(t+c(1)*h,y+h*(a(1,1)*k(1)+a(1,2)*k(2)+a(1,3)*k(3)))-k(1);
        f(t+c(2)*h,y+h*(a(2,1)*k(1)+a(2,2)*k(2)+a(2,3)*k(3)))-k(2);
        f(t+c(3)*h,y+h*(a(3,1)*k(1)+a(3,2)*k(2)+a(3,3)*k(3)))-k(3)];
k0 = [1;1;1]; 
opts = optimset('Diagnostics','off', 'Display','off');
k = fsolve(F,k0,opts);
x3  = h*(b(1)*k(1)+b(2)*k(2)+b(3)*k(3));