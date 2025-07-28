#include <bits/stdc++.h>
using namespace std;

map<int, long long> factorialCache;

long long factorial(int n) {
    if (n<=1) return 1;
    if (factorialCache.find(n)!=factorialCache.end()) {
        return factorialCache[n];
    }
    factorialCache[n]=n*factorial(n - 1);
    return factorialCache[n];
}

long long multinomialCoeff(int n, const vector<int>& k) {
    long long res=factorial(n);
    for (int ki : k) {
        res/=factorial(ki);
    }
    return res;
}

void generatePartitions(int n, int m, int idx, vector<int>& cur, vector<vector<int>>& partitions) {
    if (idx==m-1) {
        cur[idx]=n;
        partitions.push_back(cur);
        return;
    }
    for (int i=0; i<=n; i++) {
        cur[idx]=i;
        generatePartitions(n-i, m, idx+1, cur, partitions);
    }
}

double multinomialExpansion(int n, const vector<double>& a) {
    int m=a.size();
    vector<vector<int>> partitions;
    vector<int> cur(m, 0);
    generatePartitions(n, m, 0, cur, partitions);
    double res=0.0;
    for (const auto& k : partitions) {
        long long coeff=multinomialCoeff(n, k);
        double term=1.0;
        for (int i=0; i<m; i++) {
            if (k[i]>0) {
                term*=pow(a[i], k[i]);
            }
        }
        res+=coeff*term;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<double> a(m);
    for (int i=0; i<m; i++) cin>>a[i];
    double res=multinomialExpansion(n, a);
    cout<<fixed<<setprecision(0);
    if (m==2) {
        cout<<"(a1 + a2)^"<<n<<" = "<<res<<"\n";
    } else {
        cout<<"(a1 + ... + a"<<m<<")^"<<n<<" = "<<res<< "\n";
    }
    return 0;
}
