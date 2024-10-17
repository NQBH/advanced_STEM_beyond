close all
clear all
format long
warning('off')
clc

%% Initial.
N0 =20000;
h0= 40/N0;
t0 = 0:h0:40;

B = zeros(N0,2);
B(1,1) = 0.04;
B(1,2) = 0.1;

N=2000;
h=40/N;
t = 0:h:40;

A = zeros(N,2);
A(1,1) = 0.04;
A(1,2) = 0.1;

% Step 
st = N0/N;
%% Coefficients

% Explicit RK 
a1 = [0 0 0 0 ;
    1/2 0 0 0 ;
    0 1/2 0 0 ;
    0 0 1 0];
b1 = [1/6 1/3 1/3 1/6];
c1 = [0 1/2 1/2 1];

a2 = [0 0 0 0 ;
    1/3 0 0 0 ;
    -1/3 1 0 0 ;
    1 -1 1 0];
b2 = [1/8 3/8 3/8 1/8];
c2 = [0 1/3 2/3 1];

% Implicit RK
a3 = [1/4 1/4-sqrt(3)/6;
      1/4+sqrt(3)/6 1/4];
b3 = [1/2 1/2];
c3 = [1/2-sqrt(3)/6 1/2+sqrt(3)/6];

a4 = [5/36 2/9-sqrt(15)/15 5/36-sqrt(15)/30;
      5/36+sqrt(15)/24 2/9 5/36-sqrt(15)/24
      5/36+sqrt(15)/30 2/9+sqrt(15)/15 5/36];
b4 = [5/18 4/9 5/18];
c4 = [1/2-sqrt(15)/10 1/2 1/2+sqrt(15)/10];

%% Reference Solutions.
for n=1:N0
    B(n+1,:) = B(n,:) + x3(a4,b4,c4,h0,t0(n),B(n,:));
end
%% Numerical Solution.
ae = zeros(N+1,2);
re = zeros(N+1,2);

for n=1:N
    A(n+1,:) = A(n,:) + x3(a4,b4,c4,h,t(n),A(n,:));
    %     Absolute Errors
    ae(n,:) = h.*abs(A(n,:)-B(st*(n-1)+1,:));
    %     Relative Errors
    re(n,:) = h.*abs((A(n,:)-B(st*(n-1)+1,:))./B(st*(n-1)+1,:));
end

% Absolute Errors
display('Absolute Error')
ae_y1 = h*sum(ae(:,1))
ae_y2 = h*sum(ae(:,2))

% Relative Errors
display('Relative Error')
re_y1 = h*sum(re(:,1))
re_y2 = h*sum(re(:,2))

%% Plot Numerical Solution

figure(1)   
subplot(2,1,1)
hold on
plot(t0,B(:,1),'b')
% plot(t,A(:,1),'r')
legend('Exact/Reference','Numerical Solution');
title('Numerical Solution for Y1');

subplot(2,1,2)
hold on
plot(t0,B(:,2),'b')
% plot(t,A(:,2),'r')
legend('Exact/Reference','Numerical Solution');
title('Numerical Solution for Y2');
print('-r300','-djpeg');
%% Plot: Dependency of y2 with respect to y1.
figure(2)
hold on
plot(A(:,1),A(:,2),'b');
title('Dependency of y2 with respect to y1');
print('-r300','-djpeg');

%% Plot Absolute Errors.
figure(3)
subplot(2,1,1)
hold on
plot(t,ae(:,1),'b');
title('Absolute Errors Y1');

subplot(2,1,2)
hold on
plot(t,ae(:,2),'b');
title('Absolute Errors Y2');
print('-r300','-djpeg');

%% Plot Relative Errors.
figure(4)
subplot(2,1,1)
hold on
plot(t,re(:,1),'b');
title('Relative Errors Y1');

subplot(2,1,2)
hold on
plot(t,re(:,2),'b');
title('Relative Errors Y2');
print('-r300','-djpeg');