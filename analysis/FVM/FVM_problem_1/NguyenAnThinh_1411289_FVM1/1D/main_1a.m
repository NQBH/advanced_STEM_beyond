% Solve 1D Laplace equation -uxx=f(x) in [a,b]
clear all
clc
close all
ax=0.0;
bx=1.0;
a = u_exact(ax)
b = u_exact(bx)
N=5;% Number of control volume

M=4;% number of iteration when refine mesh
norml2=zeros(M,1); % norm l2;
normh1=zeros(M,1); % norrm h1

ll=zeros(M,1);

% Mean value f estimation method
k = 3;
for jj=1:M
    dx=(bx-ax)/N;
    
    % Create the mesh point
    x=zeros(N+1,1);
    for i_iter=1:N+1
        x(i_iter)=ax+(i_iter-1)*dx;
    end
    
    % create control point
    
    x_cp=zeros(N+2,1);
    for i_iter=1:N+2
        if(i_iter==1)
            x_cp(i_iter)=x(i_iter);
        else
            if(i_iter==N+2)
                x_cp(i_iter)=x(i_iter-1);
            else
                x_cp(i_iter)=(x(i_iter-1)+x(i_iter))/2.0;
            end
        end
    end
    
    % Creare the Matrix
    A=zeros(N,N);
    for i_iter=1:N
        a1=-1/((x(i_iter+1)-x(i_iter))*(x_cp(i_iter+1)-x_cp(i_iter)));
        b1=-1/((x(i_iter+1)-x(i_iter))*(x_cp(i_iter+2)-x_cp(i_iter+1)));
        if(i_iter==1)
            A(i_iter,i_iter+1)=b1;
            A(i_iter,i_iter)=-(a1+b1);
        else
            if(i_iter==N)
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter)=-(a1+b1);
            else
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter+1)=b1;
                A(i_iter,i_iter)=-(a1+b1);
            end
        end
    end
    
    % Create vector b
    F=zeros(N,1);
    for i_iter=1:N
        F(i_iter)=f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)); % Trepozoidal rule          
    end
    F(1) = F(1) + a/((x(2)-x(1))*(x_cp(2)-x_cp(1)));
    F(N) = F(N) + b/((x(N+1)-x(N))*(x_cp(N+2)-x_cp(N+1)));
    
    u=zeros(N,1);
    u=A\F;
    
    u_ex=zeros(N+2,1);
    for i_iter=1:N+2
        u_ex(i_iter)=u_exact(x_cp(i_iter));
    end
    
    u_dis=zeros(N+2,1);
    u_dis(1)=u_ex(1);
    u_dis(N+2)=u_ex(N+2);
    for i_iter=1:N
        u_dis(i_iter+1)=u(i_iter);
    end
    
     u_err = zeros(N+2,1);
    u_err = abs(u_dis - u_ex);
    err = sum(u_err)
    
    figure
    plot(x_cp,u_dis,'red',x_cp,u_ex);
    legend('Discrete', 'Exact');
    
    for i_iter=1:N
        norml2(jj)=norml2(jj)+(u_dis(i_iter+1)-u_ex(i_iter+1))^2*(x(i_iter+1)-x(i_iter));
    end
    norml2(jj)=sqrt(norml2(jj));
    
    for i_iter=1:N+1
        normh1(jj)=normh1(jj)+((u_dis(i_iter+1)-u_ex(i_iter+1))-(u_dis(i_iter)-u_ex(i_iter)))^2/(x_cp(i_iter+1)-x_cp(i_iter));
    end
    
    normh1(jj)=sqrt(normh1(jj));
    
    ll(jj)=N;
    
    N=4*N;
end

figure
plot(log(ll),-log(norml2),'r', log(ll), -log(normh1),'blue', log(ll),1.5*log(ll)+2, 'black', log(ll), 2*log(ll)+1.5,'green');
title('Error');
legend('L^2 Norm', 'H^1 norm', '3/2x', '2x')