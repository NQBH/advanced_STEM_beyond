clear all
close all
clc
format long

%% 2-DIMENSIONAL INHOMOGENEOUS INVERSE HEAT CONDUCTION PROBLEM (2-D INHOMOGENEOUS IHCP)

tic

%% Initials
test = 2; % Key of Test
l = 1; % x in [0,l]
L = -10; % Left Bound for Finite Domain [l,r]^2
R = 10;  % Right Bound for Finite Domain [l,r]^2
m = 20; % Number of Gauss-Legendre Quadrature's Nodes
n = 50; % Sampling Frequency
x_0 = -0.5; % Observed Point x_0 in l/n:l/n:l Needing Observing (Require: x_0*n must be an integer)
delta = 1e-2; % Noisy Level

%% Choose Regularization Parameters
alpha = 11; % First Regularization Parameter
% Second Regularization Parameter
% beta = 0.834931987614365; % x_0 = 0.9
% beta = 0.504354134522295; % x_0 = 0.5
beta = 0.088804031483277; % x_0 = -0.5

%% Preparations
[x_gauss,w_gauss] = lgwt(m,x_0,l); % Nodes & Weights of Gauss-Legendre Quadrature Order N
if (L == 0)
    grid = R/n:R/n:R; % Plots
elseif (R == 0)
    grid = L:-L/n:L/n; % Plots
else
    grid = linspace(L,R,n);
end
[Y,T] = meshgrid(grid); % Plots

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

%% Create Discrete Noisy Data & Discrete Noisy Source Function
PHI_delta = PHI + delta*randn(size(PHI));
PSI_delta = PSI + delta*randn(size(PSI));
F_delta = F + delta*randn(size(F));

%% Compute the Total Noises
% PHI_averaged_noise = 1/n*norm(PHI_delta - PHI,'fro');
% PSI_averaged_noise = 1/n*norm(PSI_delta - PSI,'fro');
% F_averaged_noise = 0;
% for k = 1:m
%     F_averaged_noise = F_averaged_noise + norm(F_delta(:,:,k) - F(:,:,k),'fro');
% end
% F_averaged_noise = 1/(n*sqrt(m))*sqrt(F_averaged_noise);

%% Compute Discrete Fast Fourier Transforms
f_PHI_delta = fft2(PHI_delta);
f_PSI_delta = fft2(PSI_delta);
f_F_delta = zeros(n,n,m);
for k = 1:m
    f_F_delta(:,:,k) = fft2(F_delta(:,:,k));
end

%% Compute Discrete Fourier Transform of Unregularized (with Exact vs. Noisy Data & Source Function) & Regularized Solutions
f_u_delta = zeros(n,n);
f_u_regu_delta = zeros(n,n);

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
        f_u_delta(r,s) = f_PHI_delta(r,s)*cosh((l - x_0)*theta) + ...
            f_PSI_delta(r,s)*sinh((l - x_0)*theta)/theta;
        for k = 1:m
            f_u_delta(r,s) = f_u_delta(r,s) - w_gauss(k)*f_F_delta(r,s,k)*sinh((x_gauss(k) - x_0)*theta)/theta;
        end
        
        %% Compute 2D Fourier Transform of The Regularized Solution
        f_u_regu_delta(r,s) = f_u_delta(r,s)*chi/(beta*cosh((l - x_0)*abs_theta));
    end
end

%% Compute Discrete Unregularized & Regularized Elements of the Smoothness Profile
u_delta = real(ifft2(f_u_delta));
u_regu_delta = real(ifft2(f_u_regu_delta));

%% Compute Discrete Exact Solution u(t,x,y)
u_exact = u(test,x_0,Y,T)';

%% Compute Root Mean Square Errors
RMSE_u_delta = 1/n*norm(u_delta - u_exact,'fro')
RMSE_u_regu_delta = 1/n*norm(u_regu_delta - u_exact,'fro')

%% Compute Relative Errors
RE_u_delta = n*RMSE_u_delta/norm(u_exact,'fro')
RE_u_regu_delta = n*RMSE_u_regu_delta/norm(u_exact,'fro')

toc

%% GENERATE DATA FILES
% Apply for delta = 1e-2. Use ctioga2 to Plot Contour (A Much Better Tool)
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
Mat = u_regu_delta - u_exact;
Mat = Mat(:);
Mat = [X_dat, Y_dat, Mat]

%% PLOTS SECTION

% figure(1)
% meshc(Y,T,PHI');
% hidden off
% colormap(cool(100))
% colorbar;
% axis tight
% set(gcf,'Color','w');
% get(gcf,'Renderer')
% export_fig phi -eps

% % figure(2)
% % meshc(Y,T,PSI');
% % hidden off
% % colormap(cool(100))
% % colorbar;
% % axis tight
% % set(gcf,'Color','w');
% % get(gcf,'Renderer')
% % export_fig psi -eps

% figure(2)
% meshc(Y,T,PHI_delta');
% hidden off
% colormap(cool(100))
% colorbar;
% axis tight
% set(gcf,'Color','w');
% get(gcf,'Renderer')
% export_fig(sprintf('phi_delta%d',-log10(delta)),'-eps');

% % figure(4)
% % meshc(Y,T,PSI_delta');
% % hidden off
% % colormap(cool(100))
% % colorbar;
% % axis tight
% % set(gcf,'Color','w');
% % get(gcf,'Renderer')
% % export_fig(sprintf('psi_delta%d',-log10(delta)),'-eps');

figure(3)
meshc(Y,T,u_exact');
hidden off
colormap(cool(100))
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('%u_exact_xminus%d',10*abs(x_0)),'-eps');

figure(4)
meshc(Y,T,u_delta');
hidden off
colormap(cool(100))
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('%u_delta%d_xminus%d',-log10(delta),abs(10*x_0)),'-eps');

figure(5)
meshc(Y,T,u_regu_delta');
hidden off
colormap(cool(100))
colorbar;
axis tight
set(gcf,'Color','w');
get(gcf,'Renderer')
export_fig(sprintf('%u_regu_delta%d_xminus%d',-log10(delta),abs(10*x_0)),'-eps');

%% Plot Error between Exact Solution & Regularized Solution
% figure(6)
% contour3(Y,T,(u_regu_delta - u_exact)');
% hidden off
% colormap(cool(100))
% colorbar;
% axis tight
% set(gcf,'Color','w');
% get(gcf,'Renderer')
% export_fig(sprintf('error_u_regu_delta%d_x%d',-log10(delta),abs(10*x_0)),'-eps');

%% END
