function uex=u_exact(x,k);
%uex=x*(1-x);
% uex=x*(1-x^2)+3;
% uex=(x^6+1)*(1+x^5);
%uex=x^4+2*x^3-10*x^2+2;
% uex=x^10*sin(1/(x^2-2*x+9))^4*sin(1/(5*x^3-2))^3+cos(1/(x^9+9))^2*sin(1/(x^2+x+1));
% uex=sin(pi*x)/pi/x;
% uex=sin(20*pi*x);
% uex=- x^5/20 + x^4/6 + x^3 - 10*x^2;
if k==1
    uex=(x^2*(2*x - 3))/12+1/24;
elseif k==2
    uex=1000*(x-1/20)*(x-3/11)*(x-5/12)*(x-7/9)*(x-9/10);
elseif k==3
    uex=(cos(x+1/2))^3*sin(10*pi*(x+1/2)^5)^5;
end
end