function a = Phi(k,y,t)
% Function phi(y,t) = u(0,y,t)
if (k == 1)
    a = exp(- t.^2 - y.^2 + 1);
end

if (k == 2)
    a = cos(pi*t/4).*cos(pi*y/5).*exp(1/2 - (t.^2 + y.^2)/20);
end

end
