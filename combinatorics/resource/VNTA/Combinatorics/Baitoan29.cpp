#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    if (r>n-r) r=n-r;
    long long res=1;
    for(int i=1; i<=r; i++) {
        res*=(n-r+i);
        res/=i;
    }
    return res;
}

double veTrai(int n) {
    double res=0.0;
    for(int i=0; i<=n; i++) {
        res+=(double)nCr(n,i)/(i+1) ;
    }
    return res;
}

double vePhai(int n) {
    return (1.0*(1LL<<(n+1))-1)/(n+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    cout<<"Ve trai = " << veTrai(n) << '\n';
    cout<<"Ve phai = " << vePhai(n);
}
