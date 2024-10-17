close all
clear all
format long
warning('off')
clc

%% Initial.
A(1) = 1;

N=1000;
h=25/N;
t = 0:h:25;

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

%% Numerical Solution.
for n=1:N
    A(n+1) = A(n) + x3(a4,b4,c4,h,t(n),A(n));
end

%% Plot Numerical Solution 
figure(1)
hold on
plot(t,ex(t),'b');
plot(t,A,'r');
legend('Exact Solution','Numerical Solution');
title('Solution');
print('-r300','-djpeg');


%% Absolute Error.
display('Absolute Error:')
ae = h*sum(abs(A-ex(t)))

figure(2)
hold on
plot(t,abs(A-ex(t)),'g');
title('Absolute Error');
print('-r300','-djpeg');

%% Relative Error.
display('Relative Error:')
re = h*sum(abs((A-ex(t))./ex(t)))

figure(3)
hold on
plot(t,abs((A-ex(t))./A),'g');
title('Relative Error');
print('-r300','-djpeg');