#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

//b
long long nCr(int n, int r) {
    if (r<0 || r>n) return 0;
    r = min(r, n-r);
    long long res=1;
    for (int i=0; i<r; i++) {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

long long ppow(long long a, int b) {
    long long res=1;
    while (b>0) {
        if (b%2==1) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

long long veTrai_b(int x, int m, int n) {
    long long a = ppow(x, m);
    return ppow((1-a), n);
}

long long vePhai_b(int x, int m, int n) {
    long long res=0;
    for(int i=0; i<=n; i++) {
        long long sign = (i%2==0) ? 1 : -1;
        long long a = ppow(x, i*m);
        res += sign * nCr(n,i) * a;
    }
    return res;
}

//c
double dpow(double a, double b) {
    if (b>=0) {
        double res=1.0;
        for (int i=0; i<b; i++) {
            res*=a;
        }
        return res;
    } else {
        double res=1.0;
        for (int i=0; i<-b; i++) {
            res/=a;
        }
        return res;
    }
}

double veTrai_c(double x, int m, int n) {
    double res=0;
    for(int i=0; i<=m-1; i++) {
        res+=dpow(x, i);
    }
    return dpow(res, n);
}

double vePhai_c(double x, int m, int n, int N) {
    double term1=dpow(x,m);
    double factor=dpow(1-term1, n);
    double sum=0;
    for(int i=0; i<=N-1; i++) {
        sum+=dpow(x,i);
    }
    double term2=dpow(sum,n);
    return factor*term2;
}

int main() {
    KhangGPT40_TramAnhGrok3;
    int x, m, n;
    cin>>x>>m>>n;
    cout<<"=== Cau b ===\n";
    cout<<"Ve trai = "<<veTrai_b(x,m,n)<<"\n";
    cout<<"Ve phai = "<<vePhai_b(x,m,n)<<"\n";

    cout<<"=== Cau c ===\n";
    double xc;
    cin>>xc>>m>>n;
    double veTraiC = veTrai_c(xc, m, n);
    cout<<"Ve trai = "<< veTraiC << "\n";
    vector<int> N_values = {100, 500, 1000};
    for(int N : N_values) {
        double vePhaiC = vePhai_c(xc,m,n,N);
        double d=abs(veTraiC - vePhaiC);
        cout<<"Ve phai (N="<<N<< ") = "<<vePhaiC<<", Do lech = "<<d<< "\n";
    }
    return 0;
}

/*
Input:
5 10 6
0.1 20 20
*/