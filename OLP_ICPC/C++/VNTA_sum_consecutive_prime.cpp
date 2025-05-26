#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

vector<int> eratosthenes(int N) {
    vector<bool> check(N+1, true);
    vector<int> primes;
    check[0]=check[1]=false;
    for(int i=2; i<=N; i++) {
        if (check[i]) {
            primes.push_back(i);
            for(long long j=(long long)i*i; j<=N; j+=i) {
                check[j]=false;
            }
        }
    }
    return primes;
}

int solve(int n, const vector<int>& primes) {
    int cnt=0;
    for (int i=0; i<primes.size() && primes[i]<=n; i++) {
        int sum=0;
        for (int j=i; j<primes.size() && sum<n; j++) {
            sum+=primes[j];
            if (sum==n) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(){
    KhangGPT40_TramAnhGrok3;
    vector<int>primes = eratosthenes(10000);
    int n;
    while(cin>>n && n!=0) {
        int res=solve(n, primes);
        cout<<res<<"\n";
    }
    return 0;
}
/*
2
3
17
41
20
666
12
53
0
*/
