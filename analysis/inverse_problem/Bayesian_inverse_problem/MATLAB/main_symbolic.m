clear all
close all
clc
format long

%% 2-DIMENSIONAL INHOMOGENEOUS INVERSE HEAT CONDUCTION PROBLEM (2-D INHOMOGENEOUS IHCP)

tic

%% Initials
l = 1; % x in [0,l]
N = 0; % Compute u, u_x,..., Nth partial derivative of u in x
L = -5; % Left Bound for Finite Domain [l,r]^2
R = 5;  % Right Bound for Finite Domain [l,r]^2
m = 10; % Number of Gauss-Legendre Quadrature's Nodes
n = 50; % Sampling Frequency
x_0 = 0.9; % the point x_0 in l/n:l/n:l needing observing (Require: x_0*n must be an integer)
delta = 0; % Noise Level

%% Choose Regularization Parameters
alpha = 1e-5;
kappa = 0.1;
lambda = l + N;

%% Supplementaries
[x_gauss,w_gauss] = lgwt(m,x_0,l); % Nodes & Weights of Gauss-Legendre Quadrature Order N
if (L == 0)
    grid = R/n:R/n:R; % Plots
elseif (R == 0)
    grid = L:-L/n:L/n; % Plots
else
    grid = linspace(L,R,n);
end
[Y,T] = meshgrid(grid); % Plots

%% Symbolic Computations
syms x y t;
u = exp((l-x)^2 - y^2 - t^2); % Exact solution u(x,y,t)
f = simplify(diff(u,t,1) - diff(u,x,2) - diff(u,y,2)); % Source function f(x,y,t)
Phi = simplify(subs(u,x,l)); % Cauchy data varphi(y,t)
Psi = simplify(subs(diff(u,x,1),x,l)); % Cauchy data psi(y,t)
if  (N>2)
    array_derivatives_of_f = zeros(1,N-2);
    for j = 1:N-2
        array_derivatives_of_f(j) = simplify(diff(f,x,j));
    end
end

%% Compute Matrices of Values of phi, psi, f, and derivatives of f
PHI = zeros(n,n);
PSI = zeros(n,n);
F = zeros(n,n,m);
values_of_F = zeros(n,n); % discrete version of f(x_0,y,t)
for r = 1:n
    for s = 1:n
        PHI(r,s) = subs(Phi,[y,t],[grid(r),grid(s)]);
        PSI(r,s) = subs(Psi,[y,t],[grid(r),grid(s)]);
        values_of_F(r,s) = subs(f,[x,y,t],[x_0,grid(r),grid(s)]);
        for k = 1:m
            F(r,s,k) = subs(f,[x,y,t],[x_gauss(k),grid(r),grid(s)]);
        end
    end
end
% Derivatives of f
if (N > 2)
    derivatives_of_F = zeros(n,n,N-2);
    for j = 1:N-2
        for r = 1:n
            for s = 1:n
                derivatives_of_F(r,s,j) = subs(array_derivatives_of_f(j),[x,y,t],[x_0,grid(r),grid(s)]);
            end
        end
    end
end

%% Create Discrete Noisy Data & Discrete Noisy Source Function
PHI_delta = PHI + delta*randn(size(PHI));
PSI_delta = PSI + delta*randn(size(PSI));
values_of_F_delta = values_of_F + delta*randn(size(values_of_F));
F_delta = F + delta*randn(size(F));
if (N>2)
    derivatives_of_F_delta = derivatives_of_F + delta*randn(size(derivatives_of_F));
end

% %% Compute the Total Noises
% PHI_total_noise = 1/n*norm(PHI_delta - PHI,'fro');
% PSI_total_noise = 1/n*norm(PSI_delta - PSI,'fro');
% values_of_F_total_noise = 1/n*norm(values_of_F_delta - values_of_F,'fro');
% F_total_noise = 0;
% for k = 1:m
%     F_total_noise = F_total_noise + norm(F_delta(:,:,k) - F(:,:,k),'fro');
% end
% F_total_noise = 1/(n*sqrt(m))*sqrt(F_total_noise);
% if (N>2)
%     derivatives_of_F_total_noise = zeros(1,N-2);
%     for j = 1:N-2
%         derivatives_of_F_total_noise(j) = 1/n*norm(derivatives_of_F_delta(:,:,j) - derivatives_of_F(:,:,j),'fro');
%     end
% end

%% Compute Discrete Fast Fourier Transforms
f_PHI = fft2(PHI);
f_PHI_delta = fft2(PHI_delta);
f_PSI = fft2(PSI);
f_PSI_delta = fft2(PSI_delta);
f_values_of_F = fft2(values_of_F);
f_values_of_F_delta = fft2(values_of_F_delta);
f_F = zeros(n,n,m);
f_F_delta = zeros(n,n,m);
for k = 1:m
    f_F(:,:,k) = fft2(F(:,:,k));
    f_F_delta(:,:,k) = fft2(F_delta(:,:,k));
end
if (N>2)
    f_derivatives_of_F = zeros(n,n,N-2);
    f_derivatives_of_F_delta = zeros(n,n,N-2);
    for j = 1:N-2
        f_derivatives_of_F(:,:,j) = fft2(derivatives_of_F(:,:,j));
        f_derivatives_of_F_delta(:,:,j) = fft2(derivatives_of_F_delta(:,:,j));
    end
end

%% Compute Discrete Fourier Transform of Unregularized (with Exact vs. Noisy Data & Source Function) & Regularized Solutions
% Consider cases: N is even & N is odd
for r = 1:n
    for s = 1:n
        xi = grid(r);
        tau = grid(s);
        theta = sqrt(tau*1i + xi^2);
        abs_theta = abs(theta);
        
        if (mod(N,2) == 0) % Partial derivatives of even order (N = 0 is included)
            f_even_derivative_U = zeros(n,n);
            f_even_derivative_U_delta = zeros(n,n);
            f_even_derivative_U_regu = zeros(n,n);
            f_even_derivative_U_regu_delta = zeros(n,n);
            
            %% Compute the Nth element of the smoothness profile
            % Add Cauchy data terms: varphi & psi
            f_even_derivative_U(r,s) = theta^N*f_PHI(r,s)*cosh((l-x_0)*theta) - theta^(N-1)*f_PSI(r,s)*sinh((l-x_0)*theta);
            f_even_derivative_U_delta(r,s) = theta^N*f_PHI_delta(r,s)*cosh((l-x_0)*theta) - theta^(N-1)*f_PSI_delta(r,s)*sinh((l-x_0)*theta);
            % Add integral term involving f, by Gauss-Legendre quadrature of order m
            for k = 1:m
                f_even_derivative_U(r,s) = f_even_derivative_U(r,s) - w_gauss(k)*theta^(N-1)*sinh((x_gauss(k)-x_0)*theta)*f_F(r,s,k);
                f_even_derivative_U_delta(r,s) = f_even_derivative_U_delta(r,s) - w_gauss(k)*theta^(N-1)*sinh((x_gauss(k)-x_0)*theta)*f_F_delta(r,s,k);
            end
            
            if (N >= 2)
                f_even_derivative_U(r,s) = f_even_derivative_U(r,s) - theta^(N-2)*f_values_of_F(r,s);
            end
            % Add derivatives of f if N > 2
            if (N>2)
                for j = 1:N/2-1
                    f_even_derivative_U(r,s) = f_even_derivative_U(r,s) - theta^(N-2*j-2)*f_derivatives_of_F(r,s,2*j);
                    f_even_derivative_U_delta(r,s) = f_even_derivative_U_delta(r,s) - theta^(N-2*j-2)*f_derivatives_of_F_delta(r,s,2*j);
                end
            end
            R_even = (1+alpha*abs_theta^kappa*exp(lambda*abs_theta))^((l+N-x_0)/lambda); % Regularizer
            f_even_derivative_U_regu(r,s) = f_even_derivative_U(r,s)/R_even;
            f_even_derivative_U_regu_delta(r,s) = f_even_derivative_U_delta(r,s)/R_even;
        else
            f_odd_derivative_U = zeros(n,n);
            f_odd_derivative_U_delta = zeros(n,n);
            f_odd_derivative_U_regu = zeros(n,n);
            f_odd_derivative_U_regu_delta = zeros(n,n);
            
            %% Compute the Nth element of the smoothness profile
            % Add Cauchy data terms: varphi & psi
            f_odd_derivative_U(r,s) = -theta^N*f_PHI(r,s)*sinh((l-x)*theta) + theta^(N-1)*f_PSI(r,s)*cosh((l-x)*theta);
            % Add integral term involving f, by Gauss-Legendre quadrature of order m
            for k = 1:m
                f_odd_derivative_U(r,s) = f_odd_derivative_U(r,s) - w_gauss(k)*theta^(N-1)*cosh((x_gauss(k)-x_0)*theta)*f_F(r,s,k);
                f_odd_derivative_U_delta(r,s) = f_odd_derivative_U_delta(r,s) - w_gauss(k)*theta^(N-1)*cosh((x_gauss(k)-x_0)*theta)*f_F_delta(r,s,k);
            end
            % Add derivatives of f if N > 2
            if (N>2)
                for j = 0:(N-1)/2-1
                    f_odd_derivative_U(r,s) = f_odd_derivative_U(r,s) - theta^(N-2*j-3)*f_derivatives_of_F(r,s,2*j);
                    f_odd_derivative_U_delta(r,s) = f_odd_derivative_U_delta(r,s) - theta^(N-2*j-3)*f_derivatives_of_F_delta(r,s,2*j+1);
                end
            end
        end
    end
end

%% Compute Discrete Unregularized & Regularized Elements of the Smoothness Profile
if (mod(N,2) == 0)
    derivative_U = real(ifft2(f_even_derivative_U));
    derivative_U_delta = real(ifft2(f_even_derivative_U_delta));
    derivative_U_regu = real(ifft2(f_even_derivative_U_regu));
    derivative_U_regu_delta = real(ifft2(f_even_derivative_U_regu_delta));
else
    derivative_U = real(ifft2(f_odd_derivative_U));
    derivative_U_delta = real(ifft2(f_odd_derivative_U_delta));
    derivative_U_regu = real(ifft2(f_odd_derivative_U_regu));
    derivative_U_regu_delta = real(ifft2(f_odd_derivative_U_regu_delta));
end

%% Exact Nth Element of the Smoothness Profile
derivative_U_exact = zeros(n,n);
for r = 1:n
   for s = 1:n
       derivative_U_exact(r,s) = subs(diff(u,x,N),{x,y,t},{x_0,grid(r),grid(s)});
   end
end

%% Compute RMSE
RMSE_derivative_U = 1/n*norm(derivative_U - derivative_U_exact,'fro')
RMSE_derivative_U_delta = 1/n*norm(derivative_U_delta - derivative_U_exact,'fro')
RMSE_derivative_U_regu = 1/n*norm(derivative_U_regu - derivative_U_exact,'fro')
RMSE_derivative_U_regu_delta = 1/n*norm(derivative_U_regu_delta - derivative_U_exact,'fro')

toc

%% GENERATE DATA FILES
% Apply for delta = 1e-2. Use ctioga2 to plot contour (much better tool)
X_dat = zeros(n^2,1);
Y_dat = zeros(n^2,1);
for i = 1:n^2
    X_dat(i) = grid(fix((i-1)/n) + 1);
    if (rem(i,n) == 0)
        Y_dat(i) = grid(n);
    else
        Y_dat(i) = grid(rem(i,n));
    end
end
Mat = derivative_U_regu_delta - derivative_U_exact;
Mat = Mat(:);
Mat = [X_dat, Y_dat, Mat];

%% PLOTS SECTION

figure(1)
meshc(Y,T,PHI');
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig phi -eps

% % figure(2)
% % meshc(Y,T,PSI');
% % hidden off
% % colormap jet
% % colorbar;
% % axis tight
% % set(gcf,'Color','w');
% % get(gcf,'Renderer')
% % export_fig psi -eps

figure(3)
meshc(Y,T,PHI_delta');
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('phi_delta%d',-log10(delta)),'-eps');

% % figure(4)
% % meshc(Y,T,PSI_delta');
% % hidden off
% % colormap jet
% % colorbar;
% % axis tight
% % set(gcf,'Color','w');
% % get(gcf,'Renderer')
% % export_fig(sprintf('psi_delta%d',-log10(delta)),'-eps');

figure(5)
meshc(Y,T,derivative_U_exact);
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('derivative_U_exact_x%d',10*x_0),'-eps');

figure(7)
meshc(Y,T,derivative_U_delta');
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('derivative_U_delta%d_x%d',-log10(delta),10*x_0),'-eps');

figure(9)
meshc(Y,T,derivative_U_regu_delta');
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('derivative_U_regu_delta%d_x%d',-log10(delta),10*x_0),'-eps');

%% Plot Error between Exact Solution & Regularized Solution
figure(16)
contour3(Y,T,(derivative_U_regu_delta - derivative_U_exact)');
hidden off
colormap jet
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('error_derivative_U_regu_delta%d_x%d',-log10(delta),10*x_0),'-eps');

%% Compute Relative Errors
Relative_error_derivative_U = norm(derivative_U - derivative_U_exact,'fro')/norm(derivative_U_exact,'fro')
Relative_error_derivative_U_delta = norm(derivative_U_delta - derivative_U_exact,'fro')/norm(derivative_U_exact,'fro')
Relative_error_derivative_U_regu = norm(derivative_U_regu - derivative_U_exact,'fro')/norm(derivative_U_exact,'fro')
Relative_error_derivative_U_regu_delta = norm(derivative_U_regu_delta - derivative_U_exact,'fro')/norm(derivative_U_exact,'fro')

%% END
