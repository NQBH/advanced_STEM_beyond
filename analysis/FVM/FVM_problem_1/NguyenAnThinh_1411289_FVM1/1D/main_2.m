% Solve 1D Laplace equation -uxx=f(x) in [a,b]
clear all
clc
close all
ax=0.0;
bx=1.0;

N=5;% Number of control volume

M=4;% number of iteration when refine mesh
norml2=zeros(M,1); % norm l2;
normh1=zeros(M,1); % norrm h1

ll=zeros(M,1);

% Mean value f estimation method
k = 1;
for jj=1:M
        
    
%     
%     % Create the mesh point
%     dx=(bx-ax)/N;
%     x=zeros(N+1,1);
%     for i_iter=1:N+1
%         x(i_iter)=ax+(i_iter-1)*dx;
%     end
    
    % Create the mesh point
    x=zeros(N+1,1);
    for i_iter=1:N+1
        x(i_iter)=1-cos(pi*i_iter/2/(N+1));
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
%                 x_cp(i_iter)=2*x(i_iter-1)/3 + x(i_iter)/3;
            end
        end
    end
    
    
    % Creare the Matrix A and F
    A=zeros(N+1,N);
    F=zeros(N+1,1);
    for i_iter=1:N
        d1 = x_cp(i_iter+1)-x_cp(i_iter);
        d2 = x_cp(i_iter+2)-x_cp(i_iter+1);
        t1 = x(i_iter+1)-x(i_iter);
        if(i_iter==1)
            A(i_iter,i_iter+1)=-1/(t1*d2);
            A(i_iter,i_iter)=1/(t1*d2);
            t2 = x(i_iter+2)-x(i_iter+1);
            A(N+1,i_iter) = (x_cp(i_iter+2)+x_cp(i_iter+1)-2*x_cp(i_iter))/2;
            F(N+1) = -d1^3*f(ax)/4;
            F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) + (t2^2-t1^2)*f(x(i_iter+1))/(8*d2*t1);
%             F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) + (t2^2-4*t1^2)*f(x(i_iter+1))/(18*d2*t1) ;
        else
            if(i_iter==N)
                A(i_iter,i_iter-1)=-1/(t1*d1);
                A(i_iter,i_iter)=1/(t1*d1);
                t0 = x(i_iter)-x(i_iter-1);
                A(N+1,i_iter) = (2*x_cp(i_iter+2)-x_cp(i_iter+1)-x_cp(i_iter))/2;
                F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) - (t1^2-t0^2)*f(x(i_iter))/(8*d1*t1); 
                F(N+1) = F(N+1)-d2^3*f(bx)/4;
%                 F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) - (t1^2-4*t0^2)*f(x(i_iter))/(18*d1*t1) ;
            else
                A(i_iter,i_iter-1)=-1/(t1*d1);
                A(i_iter,i_iter+1)=-1/(t1*d2);
                A(i_iter,i_iter)=1/(t1*d1)+1/(t1*d2);
                t0 = x(i_iter)-x(i_iter-1);
                t2 = x(i_iter+2)-x(i_iter+1);
                A(N+1,i_iter) = (x_cp(i_iter+2)-x_cp(i_iter))/2;
                F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) + (t2^2-t1^2)*f(x(i_iter+1))/(8*d2*t1) - (t1^2-t0^2)*f(x(i_iter))/(8*d1*t1) ;
%                 F(i_iter)= f_apx(x,i_iter,k)/(x(i_iter+1)-x(i_iter)) + (t2^2-4*t1^2)*f(x(i_iter+1))/(18*d2*t1) - (t1^2-4*t0^2)*f(x(i_iter))/(18*d1*t1) ;
            end
        end
    end

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
    
    figure
    plot(x_cp,u_dis,'red',x_cp,u_ex);
    legend('Discrete', 'Exact');
    title('Solution');
    
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