function uex=u_exact(x,k);
if k==1
    uex=(x^2*(2*x - 3))/12+1/24;
elseif k==2
    uex=sin(20*pi*x+pi/2);
elseif k==3
%     uex=(cos(x+1/2))^3*sin(10*pi*(x+1/2)^5)^5;
end
end