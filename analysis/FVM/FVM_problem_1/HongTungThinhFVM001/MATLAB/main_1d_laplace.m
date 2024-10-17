% Solve 1D Laplace equation -uxx=f(x) in [a,b]
format long
clear all
% clc
close all

ax=0;
bx=1;

cases=1;
BC=1;
grid=1;
cp=1;
integration=1; % Integration rule

fprintf('Case %d\n',cases);
if BC==1
    fprintf('Dirichlet Boundary Condition\n');
    bc='dirichlet';
elseif BC==2
    fprintf('Neumann Boundary Condition\n');
    bc='neumann';
elseif BC==3
    fprintf('Robin Boundary Condition\n');
    bc='robin';
end

if cases == 1
    N=4;% Number of control volume
    N0=N;
    M=6;% number of iteration when refine mesh
    if BC==1
        C0=1/24;
        C1=-1/24;
    elseif BC==2
        C0=0;
        C1=0;
        C=0;
    elseif BC==3
        L0=-1;
        L1=1;
        C0=1/24;
        C1=-1/24;
    end
    it=1;
elseif cases == 2
    N=4;% Number of control volume
    N0=N;
    M=12;% number of iteration when refine mesh
    if BC==1
        C0=1;
        C1=1;
    elseif BC==2
        C0=0;
        C1=0;
        C=0;
    elseif BC==3
        L0=-1;
        L1=-2;
        C0=1;
        C1=-2;
    end
    it=1;
elseif cases == 3
    N=4;% Number of control volume
    N0=N;
    M=6;% number of iteration when refine mesh
    if BC==1
        C0=-175/44;
        C1=2660/297;
    elseif BC==2
        C0=22415/198;
        C1=99175/594;
        C=5495/7128;
    elseif BC==3
        L0=-1;
        L1=0;
        C0=-175/44+22415/198;
        C1=99175/594;
    end
    it=1;
elseif cases == 4
    N=100;% Number of control volume
    N0=N;
    M=10;% number of iteration when refine mesh
    if BC==1
        C0=0;
        C1=0;
    elseif BC==2
        C0=0;
        C1=0;
        C=0.056334049139993;
    elseif BC==3
        L0=0;
        L1=3;
        C0=0;
        C1=0;
    end
    it=1;
elseif cases == 5
    N=100;% Number of control volume
    N0=N;
    M=30;% number of iteration when refine mesh
    if BC==1
        C0=0;
        C1=0;
    elseif BC==2
        C0=0;
        C1=0;
        C=0;
    elseif BC==3
        L0=-1;
        L1=1;
        C0=0;
        C1=0;
    end
    it=2;    
elseif cases == 6
    N=100;% Number of control volume
    N0=N;
    M=10;% number of iteration when refine mesh
    if BC==1
        C0=sin((5*pi)/16)^5*cos(1/2)^3;
        C1=-sin(pi/16)^5*cos(3/2)^3;
    elseif BC==2
        C0=-(cos(1/2)^2*(24*sin((5*pi)/16)*sin(1/2) - 125*pi*cos((5*pi)/16)*cos(1/2))*((2 - 2^(1/2))^(1/2)/4 - 2^(1/2)/16 + 3/8))/8;
        C1=(3*cos(3/2)^2*(8*sin(pi/16)*sin(3/2) + 3375*pi*cos(pi/16)*cos(3/2))*(2^(1/2)/16 - (2^(1/2) + 2)^(1/2)/4 + 3/8))/8;
        C=0.033404805943832;
    elseif BC==3
        L0=-1;
        L1=1;
        C0=sin((5*pi)/16)^5*cos(1/2)^3-(cos(1/2)^2*(24*sin((5*pi)/16)*sin(1/2) - 125*pi*cos((5*pi)/16)*cos(1/2))*((2 - 2^(1/2))^(1/2)/4 - 2^(1/2)/16 + 3/8))/8;
        C1=-sin(pi/16)^5*cos(3/2)^3+(3*cos(3/2)^2*(8*sin(pi/16)*sin(3/2) + 3375*pi*cos(pi/16)*cos(3/2))*(2^(1/2)/16 - (2^(1/2) + 2)^(1/2)/4 + 3/8))/8;
    end
    it=1;    
end

norml2=zeros(M,1); % L2 norm
norme=zeros(M,1); % Energy norm

% grid=1;
if grid==1
    fprintf('Uniform grid\n');
    gr='uniform';
elseif grid==2
    fprintf('Singular grid\n');
    gr='singular';
end

% cp=2;
if cp==1
    fprintf('Each control point is the midpoint of the corresponding control volume\n');
    cps='midpoint_cp';
elseif cp==2
    fprintf('Each control point is 1/3 to the left of the corresponding control volume\n');
    cps='left_cp';
end

% integration=1; % Integration rule
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
    
    % create control point
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
        c1=-1/((x(i_iter+1)-x(i_iter))*(x_cp(i_iter+2)-x_cp(i_iter+1)));
        b1=-a1-c1;
        
        if integration==1
            b(i_iter)=f((x(i_iter)+x(i_iter+1))/2.0,cases);
        elseif integration==2
            b(i_iter)=(f(x(i_iter),cases)+f(x(i_iter+1),cases))/2;
        elseif integration==3
            b(i_iter)=(f(x(i_iter),cases)+4*f((x(i_iter)+x(i_iter+1))/2,cases)+f(x(i_iter+1),cases))/6;
        elseif integration==4
            b(i_iter)=(7*f(x(i_iter),cases)+32*f((x(i_iter)+3*x(i_iter+1))/4,cases)+12*f((x(i_iter)+x(i_iter+1))/2,cases)+32*f((3*x(i_iter)+x(i_iter+1))/4,cases)+7*f(x(i_iter+1),cases))/90;        
        end
        
        if BC==1
            if(i_iter==1)
                A(i_iter,i_iter+1)=c1;
                A(i_iter,i_iter)=b1;
                b(i_iter)=b(i_iter)-a1*C0;
            else
                if(i_iter==N)
                    A(i_iter,i_iter-1)=a1;
                    A(i_iter,i_iter)=b1;
                    b(i_iter)=b(i_iter)-c1*C1;
                else
                    A(i_iter,i_iter-1)=a1;
                    A(i_iter,i_iter+1)=c1;
                    A(i_iter,i_iter)=b1;
                end
             end
        elseif BC==2
            if(i_iter==1)
                A(i_iter,i_iter+1)=c1;
                A(i_iter,i_iter)=-c1;
                b(i_iter)=b(i_iter)+a1*C0*(x_cp(2)-x_cp(1));
            else
                if(i_iter==N)
                    A(i_iter,i_iter-1)=a1;
                    A(i_iter,i_iter)=-a1;
                    b(i_iter)=b(i_iter)-c1*C1*(x_cp(N+2)-x_cp(N+1));
                else
                    A(i_iter,i_iter-1)=a1;
                    A(i_iter,i_iter+1)=c1;
                    A(i_iter,i_iter)=b1;
                end
        end
        elseif BC==3
            if(i_iter==1)
            A(i_iter,i_iter+1)=c1;
            A(i_iter,i_iter)=a1/(1+L0*(x_cp(2)-x_cp(1)))+b1;
            b(i_iter)=b(i_iter)+a1*C0*(x_cp(2)-x_cp(1))/(1+L0*(x_cp(2)-x_cp(1)));
        else
            if(i_iter==N)
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter)=b1+c1/(1+L1*(x_cp(N+2)-x_cp(N+1)));
                b(i_iter)=b(i_iter)-c1*C1*(x_cp(N+2)-x_cp(N+1))/(1+L1*(x_cp(N+2)-x_cp(N+1)));
                
            else
                A(i_iter,i_iter-1)=a1;
                A(i_iter,i_iter+1)=c1;
                A(i_iter,i_iter)=b1;
            end
        end
        end
        
    end  
    
    if BC==1
        u=zeros(N,1);
        u=A\b;
        u_dis=zeros(N+2,1);
        u_dis(1)=C0;
        u_dis(N+2)=C1;
    elseif BC==2
        K = 3;
        A(:,K)=[];
        A(K,:)=[];
        b(K)=[];
        u=A\b;
        u=[u(1:K-1) ; 0 ; u(K:length(u))];
        su=-C;
        for i=1:N
            su=su+u(i)*(x(i+1)-x(i));
        end
        u=u-su;
        u_dis=zeros(N+2,1);
        u_dis(1)=u(1)-C0*(x_cp(2)-x_cp(1));
        u_dis(N+2)=u(N)+C1*(x_cp(N+2)-x_cp(N+1));
    elseif BC==3
        u=zeros(N,1);
        u=A\b;
        u_dis=zeros(N+2,1);
        u_dis(1)=(u(1)-C0*(x_cp(2)-x_cp(1)))/(1+L0*(x_cp(2)-x_cp(1)));
        u_dis(N+2)=(u(N)+C1*(x_cp(N+2)-x_cp(N+1)))/(1+L1*(x_cp(N+2)-x_cp(N+1)));
    end
    
    u_ex=zeros(N+2,1);
    for i_iter=1:N+2
        u_ex(i_iter)=u_exact(x_cp(i_iter),cases);
    end
    
    for i_iter=1:N
        u_dis(i_iter+1)=u(i_iter);
    end
    
    fig=figure(jj);
    set(fig, 'PaperSize', [5 6]);
    plot(x_cp,u_dis,'red',x_cp,u_ex,'blue');
    str=sprintf('Discrete and exact solutions, N = %d',N);
    title(str);
    legend('Discrete solution', 'Exact solution');
    filename=sprintf('fig_%s_result_G%d_CP%d_I%d_N%d_M%d_C%d.pdf',bc,grid,cp,integration,N,M,cases);
    orient(fig,'landscape');
    fig.PaperPositionMode = 'auto';
%     saveas(fig,filename);
    fprintf(filename); fprintf('\n');
    
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
set(fig, 'PaperSize', [5 6]);
if cases == 1
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)+2, 'black', log(ll), 2*log(ll)+2.5,'green', log(ll), log(ll)+2.5,'magenta');
elseif cases == 2
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-7.5, 'black', log(ll), 2*log(ll)-6.1,'green', log(ll), log(ll)-11,'magenta');    
elseif cases == 3
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-6, 'black', log(ll), 2*log(ll)-6,'green', log(ll), log(ll)-5.5,'magenta');
elseif cases == 4
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-9.5, 'black', log(ll), 2*log(ll)-6,'green', log(ll), log(ll)-11,'magenta');
elseif cases ==5
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-9.5, 'black', log(ll), 2*log(ll)-6,'green', log(ll), log(ll)-11,'magenta');
elseif cases ==6
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll)-9.5, 'black', log(ll), 2*log(ll)-6,'green', log(ll), log(ll)-11,'magenta');
else
    plot(log(ll),-log(norml2),'r', log(ll), -log(norme),'blue', log(ll),1.5*log(ll), 'black', log(ll), 2*log(ll),'green', log(ll), log(ll),'magenta');
end

title('Error');
legend('L^2 Norm', 'H^1 norm', '3/2x', '2x','1x','Location','northeastoutside');
filename=sprintf('fig_%s_error_G%d_CP%d_I%d_M%d_C%d.pdf',bc,grid,cp,integration,M,cases);
orient(fig,'landscape');
fig.PaperPositionMode = 'auto';
saveas(fig,filename);
fprintf(filename); fprintf('\n');