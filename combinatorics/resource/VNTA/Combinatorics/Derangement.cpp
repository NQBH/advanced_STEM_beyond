#include<bits/stdc++.h>
using namespace std;

long long countDerangement(int n) {
    vector<int>p(n);
    for(int i=0; i<n; i++) p[i]=i+1;
    int cnt=0;
    do {
        bool check=true;
        for(int i=0; i<n; i++) {
            if (p[i]==i+1) {
                check=false;
                break;
            }
        }
        if (check) cnt++;
    } while (next_permutation(p.begin(), p.end()));
    return cnt;
}

long long Pn(int n) {
    long long res=1;
    for(int i=2; i<=n; i++) res*=i;
    return res;
}

long long calDerangement(int n) {
    long double sum=0;
    for(int i=0; i<=n; i++) {
        long double t=pow(-1,i)/Pn(i);
        sum+=t;
    }
    long long res=round(Pn(n)*sum);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    const double E = exp(1.0);
    long long f = floor((Pn(n)+1)/E);
    cout<<"So hoan vi (generate): "<<countDerangement(n)<<"\n";
    cout<<"So hoan vi (calculate): "<<calDerangement(n)<<"\n";
    cout<<"So nguyen gan nhat voi n!/e: "<<f;
}
