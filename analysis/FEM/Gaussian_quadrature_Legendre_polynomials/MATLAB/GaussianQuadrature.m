function [X,C] = GaussianQuadrature(n)
if (n < 1)
    disp('Unacceptable: n must > 0');
    X = [];
    C = [];
else
    syms x;
    % Initial Values.
    b = zeros(2*n,1);
    B = zeros(n);
    V = zeros(n);
    for i = 1:2*n
        if (mod(i,2) ~= 0)
            b(i) = 2/i;
        end
    end
    for i = 1:n
        for j = 1:n
            B(i,j) = b(n+i-j);
        end
    end
    % Solve related system of equations.
    A = -B\b(n+1:2*n);
    % Create a polynomial containing weight points.
    P = poly2sym([1;A],x);
    % Find weigt points.
    X = solve(P,x);
    for i = 1:n
        for j = 1:n
            V(i,j) = X(j)^(i-1);
        end
    end
    % Find weights.
    C = V\b(1:n);
end

