function x2 = x2(a,b,c,h,t,y)

F1=@(k1) [f1(t+c(1)*h,y+h*(a(1,1)*k1(1)+a(1,2)*k1(2)))-k1(1);
          f1(t+c(2)*h,y+h*(a(2,1)*k1(1)+a(2,2)*k1(2)))-k1(2)];
F2=@(k2) [f2(t+c(1)*h,y+h*(a(1,1)*k2(1)+a(1,2)*k2(2)))-k2(1);
          f2(t+c(2)*h,y+h*(a(2,1)*k2(1)+a(2,2)*k2(2)))-k2(2)];
k0 = [1;1];
opts = optimset('Diagnostics','off', 'Display','off');
k1 = fsolve(F1,k0,opts);
k2 = fsolve(F2,k0,opts);
x2(1) = h*(b(1)*k1(1)+b(2)*k1(2));
x2(2) = h*(b(1)*k2(1)+b(2)*k2(2));