function x3 = x3(a,b,c,h,t,y)
F1=@(k1) [f1(t+c(1)*h,y+h*(a(1,1)*k1(1)+a(1,2)*k1(2)+a(1,3)*k1(3)))-k1(1);
          f1(t+c(2)*h,y+h*(a(2,1)*k1(1)+a(2,2)*k1(2)+a(2,3)*k1(3)))-k1(2);
          f1(t+c(3)*h,y+h*(a(3,1)*k1(1)+a(3,2)*k1(2)+a(3,3)*k1(3)))-k1(3)];
 
F2=@(k2) [f2(t+c(1)*h,y+h*(a(1,1)*k2(1)+a(1,2)*k2(2)+a(1,3)*k2(3)))-k2(1);
          f2(t+c(2)*h,y+h*(a(2,1)*k2(1)+a(2,2)*k2(2)+a(2,3)*k2(3)))-k2(2);
          f2(t+c(3)*h,y+h*(a(3,1)*k2(1)+a(3,2)*k2(2)+a(3,3)*k2(3)))-k2(3)];     
k0 = [1;1;1]; 
opts = optimset('Diagnostics','off', 'Display','off');
k1 = fsolve(F1,k0,opts);
k2 = fsolve(F2,k0,opts);
x3(1) = h*(b(1)*k1(1)+b(2)*k1(2)+b(3)*k1(3));
x3(2) = h*(b(1)*k2(1)+b(2)*k2(2)+b(3)*k2(3));