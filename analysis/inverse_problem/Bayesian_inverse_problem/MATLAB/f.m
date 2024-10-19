function a = f(k,x,y,t)
% Source Function f(x,y,t)
if (k == 1)
   a = -2*exp((x - 2).^2 - t.^2 - y.^2).*(2*x.^2 - 8*x + 2*y.^2 + t + 8);
end

if (k == 2)
   a = -(exp((x - 2)^2/2 - t^2/20 - y^2/20)*(490*cos((pi*t)/4)*cos((pi*y)/5) ... 
   - 4*pi^2*cos((pi*t)/4)*cos((pi*y)/5) + 100*x^2*cos((pi*t)/4)*cos((pi*y)/5) + ...
   y^2*cos((pi*t)/4)*cos((pi*y)/5) + 25*pi*cos((pi*y)/5)*sin((pi*t)/4) + ...
   10*t*cos((pi*t)/4)*cos((pi*y)/5) - 400*x*cos((pi*t)/4)*cos((pi*y)/5) + ...
   4*pi*y*cos((pi*t)/4)*sin((pi*y)/5)))/100;
end

end
