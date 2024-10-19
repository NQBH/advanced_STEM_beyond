function a = u(k,x,y,t)
% Exact Solution u(x,y,t)
if (k == 1)
    a = exp((2 - x).^2 - t.^2 - y.^2);
end

if (k == 2)
    a = cos(pi*t/4).*cos(pi*y/5).*exp((2-x).^2/2 - (t.^2 + y.^2)/20);
end

end
