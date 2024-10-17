function x2 = x2(a,b,c,h,t,y)

F=@(k) [f(t+c(1)*h,y+h*(a(1,1)*k(1)+a(1,2)*k(2)))-k(1);
        f(t+c(2)*h,y+h*(a(2,1)*k(1)+a(2,2)*k(2)))-k(2)];
k0 = [1;1];
opts = optimset('Diagnostics','off', 'Display','off');
k = fsolve(F,k0,opts);
x2  = h*(b(1)*k(1)+b(2)*k(2));