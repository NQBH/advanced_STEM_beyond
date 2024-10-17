% Solve 1D Laplace equation -uxx=f(x) in [a,b]
clear all
clc
format long
close all
ax=0.0;
bx=1.0;

cases=2;
fprintf('Case %d\n',cases);

if cases == 1
    N=4;% Number of control volume
    M=6;% number of iteration when refine mesh
    it=1;
elseif cases == 2
    N=4;% Number of control volume
    M=9;% number of iteration when refine mesh
    it=1;
%     N0=500;
% elseif cases == 3
%     N=;% Number of control volume
%     M=;% number of iteration when refine mesh
%     it=2;
end

norml2=zeros(M,1); % L2 norm
norme=zeros(M,1); % Energy norm

grid=1;
if grid==1
    fprintf('Uniform grid\n');
    gr='uniform';
elseif grid==2
    fprintf('Singular grid\n');
    gr='singular';
end

cp=1;
if cp==1
    fprintf('Each control point is the midpoint of corresponding control volume\n');
    cps='midpoint_cp';
elseif cp==2
    fprintf('Each control point is 1/3 to the left of corresponding control volume\n');
    cps='left_cp';
end

integration=1; % Integration rule
if integration==1
    fprintf('Integration using Midpoint rule\n');
    inte='midpoint';
elseif integration==2
    fprintf('Integration using Trepozoidal rule\n');
    inte='trepozoidal';
elseif integration==3
    fprintf('Integration using Simpson rule\n');
    inte='simpson';
elseif integration==4
    fprintf('Integration using Boole rule\n');
    inte='boole';
end

ll=zeros(M,1);

for jj=1:M
    fprintf('N=%d\n',N);
    % Create the mesh point
    if grid==1
        dx=(bx-ax)/N;
        for i_iter=1:N+1
            x(i_iter)=ax+(i_iter-1)*dx;
        end
    elseif grid==2
        for i=1:N+1
            x(i) = ax + (1-cos(pi*i/2/(N+1)))*(bx-ax);
        end
    end    

    % Create control point
    x_cp=zeros(N+2,1);
    for i_iter=1:N+2
        if(i_iter==1)
            x_cp(i_iter)=x(i_iter);
        else
            if(i_iter==N+2)
                x_cp(i_iter)=x(i_iter-1);
            else
                if cp==1
                    x_cp(i_iter)=(x(i_iter-1)+x(i_iter))/2;
                elseif cp==2
                    x_cp(i_iter)=(2*x(i_iter-1)+x(i_iter))/3;  
                end
            end
        end
    end
    
    % Creare the Matrix A and the vector b
    A=zeros(N,N);
    b=zeros(N,1);
    for i_iter=1:N
        a1=-1/((x(i_iter+1)-x(i_iter))*(x_cp(i_iter+1)-x_cp(i_iter)));
        b1=-1/((x(i_iter+1)-x(i_iter))*(x_cp(i_iter+2)-x_cp(i_iter+1)));
        
        if integration==1
            b(i_iter)=f((x(i_iter)+x(i_iter+1))/2.0,cases);
        elseif integration==2
            b(i_iter)=(f(x(i_iter),cases)+f(x(i_iter+1),cases))/2.0;
        elseif integration==3
            b(i_iter)=(f(x(i_iter),cases)+4*f((x(i_iter)+x(i_iter+1))/2.0,cases)+f(x(i_iter+1),cases))/6;
        elseif integration==4
            b(i_iter)=(7*f(x(i_iter),cases)+32*f((x(i_iter)+3*x(i_iter+1))/4,cases)+12*f((x(i_iter)+x(i_iter+1))/2,cases)+32*f((3*x(i_iter)+x(i_iter+1))/4,cases)+7*f(x(i_iter+1),cases))/90;        
        end
        
        if(i_iter==1)
            A(i_iter,i_iter+1)=b1;
            A(i_iter,i_iter)=-b1;
        else
            if(i_iter==N)
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter)=-a1;
            else
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter+1)=b1;
                A(i_iter,i_iter)=-(a1+b1);
            end
        end
    end
    
    %
    K = 3;
    A(:,K)=[];
    A(K,:)=[];
    b(K)=[];
    
    u=A\b;
    
    u=[u(1:K-1) ; 0 ; u(K:length(u))];
    su=0;
    for i=1:N
        su=su+u(i)*(x(i+1)-x(i));
    end

    u=u-su;
    
    u_ex=zeros(N+2,1);
    for i_iter=1:N+2
        u_ex(i_iter)=u_exact(x_cp(i_iter),cases);
    end
    
    u_dis=zeros(N+2,1);
    u_dis(1)=u(1);
    u_dis(N+2)=u(N);
    for i_iter=1:N
        u_dis(i_iter+1)=u(i_iter);
    end
    
    fig=figure(jj);
%     set(fig,'PaperUnits','normalized');
%     set(fig,'PaperPosition',[.25 .25 8 6])
    set(fig, 'PaperSize', [5 6]);
    plot(x_cp,u_dis,'red',x_cp,u_ex,'blue');
    str=sprintf('Discrete and exact solutions, N = %d',N);
    title(str);
    legend('Discrete solution', 'Exact solution');
    filename=sprintf('fig_neumann_result_G%d_CP%d_I%d_N%d_M%d_C%d.pdf',grid,cp,integration,N,M,cases);
    fprintf(filename); fprintf('\n');
    orient(fig,'landscape');
    fig.PaperPositionMode = 'auto';
    print(fig,filename,'-dpdf');
    saveas(fig,filename);

    for i_iter=1:N
        norml2(jj)=norml2(jj)+(u_dis(i_iter+1)-u_ex(i_iter+1))^2*(x(i_iter+1)-x(i_iter));
    end
    norml2(jj)=sqrt(norml2(jj));
    fprintf('Error in L^2 norm: %df\n',norml2(jj));
    
    for i_iter=1:N+1
        norme(jj)=norme(jj)+((u_dis(i_iter+1)-u_ex(i_iter+1))-(u_dis(i_iter)-u_ex(i_iter)))^2/(x_cp(i_iter+1)-x_cp(i_iter));
    end
    
    norme(jj)=sqrt(norme(jj));
    fprintf('Error in energy norm: %df\n',norme(jj));

    ll(jj)=N;
    if it==1
        N=2*N;
    elseif it==2
        N=N+N0;
    end
    fprintf('\n');
end

fig=figure(jj+1);
% set(fig,'PaperUnits','normalized');
% set(fig,'PaperPosition',[.25 .25 8 6])
set(fig, 'PaperSize', [5 6]);
% plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll), 'black', log(ll), 2*log(ll),'green', log(ll), log(ll),'magenta');
if cases == 1
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)+2, 'black', log(ll), 2*log(ll)+4.4,'green', log(ll), log(ll)+3,'magenta');
elseif cases == 2
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-7, 'black', log(ll), 2*log(ll)-5.5,'green', log(ll), log(ll)-6,'magenta');
% elseif cases == 3
%     plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-9.5, 'black', log(ll), 2*log(ll)-7,'green', log(ll), log(ll)-12,'magenta');
end

title('Error');
legend('L^2 Norm', 'H^1 norm', '3/2x', '2x','1x','Location','northeastoutside');
filename=sprintf('fig_neumann_error_G%d_CP%d_I%d_M%d_C%d.pdf',grid,cp,integration,M,cases);
fprintf(filename); fprintf('\n');
orient(fig,'landscape');
fig.PaperPositionMode = 'auto';
% print(fig,filename,'-dpdf');
saveas(fig,filename);