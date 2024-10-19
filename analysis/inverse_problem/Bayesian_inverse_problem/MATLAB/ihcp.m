function [u_regu,grid] = ihcp(alpha,beta,x_0)

%% Initials
l = 1; % x in [0,l]
test = 2;
L = -10; % Left Bound for Finite Domain [l,r]^2
R = 10; % Right Bound for Finite Domain [l,r]^2
m = 20; % Number of Gauss-Legendre Quadrature's Nodes
n = 50; % Sampling Frequency

%% Preparations
[x_gauss,w_gauss] = lgwt(m,x_0,l); % Nodes & Weights of Gauss-Legendre Quadrature Order N
if (L == 0)
    grid = R/n:R/n:R; % Plots
elseif (R == 0)
    grid = L:-L/n:L/n; % Plots
else
    grid = linspace(L,R,n);
end

%% Compute Matrices of Values of phi, psi, f, and derivatives of f
PHI = zeros(n,n);
PSI = zeros(n,n);
F = zeros(n,n,m);

for r = 1:n
    for s = 1:n
        PHI(r,s) = Phi(test,grid(r),grid(s));
        PSI(r,s) = Psi(test,grid(r),grid(s));
        for k = 1:m
            F(r,s,k) = f(test,x_gauss(k),grid(r),grid(s));
        end
    end
end

%% Compute Discrete Fast Fourier Transforms
f_PHI = fft2(PHI);
f_PSI = fft2(PSI);
f_F = zeros(n,n,m);
for k = 1:m
    f_F(:,:,k) = fft2(F(:,:,k));
end

%% Compute Discrete Fourier Transform of Unregularized (with Exact vs. Noisy Data & Source Function) & Regularized Solutions
f_u = zeros(n,n);
f_u_regu = zeros(n,n);

for r = 1:n
    for s = 1:n
        zeta = grid(r);
        tau = grid(s);
        theta = sqrt(tau*1i + zeta^2);
        abs_theta = abs(theta);
        
        %% Compute Truncated Characteristic Function
        chi = 0;
        if ((tau^2 + zeta^4) < alpha^4) % or abs_theta < alpha
            chi = 1;
        end
        
        %% Compute 2D Fourier Transform of The Unregularized Solution
        f_u(r,s) = f_PHI(r,s)*cosh((l - x_0)*theta) + ...
            f_PSI(r,s)*sinh((l - x_0)*theta)/theta;
        for k = 1:m
            f_u(r,s) = f_u(r,s) - w_gauss(k)*f_F(r,s,k)*sinh((x_gauss(k) - x_0)*theta)/theta;
        end
        
        %% Compute 2D Fourier Transform of The Regularized Solution
        f_u_regu(r,s) = f_u(r,s)*chi/(beta*cosh((l - x_0)*abs_theta));
    end
end

%% Compute Discrete Regularized Solutions of the Smoothness Profile
u_regu = real(ifft2(f_u_regu));
