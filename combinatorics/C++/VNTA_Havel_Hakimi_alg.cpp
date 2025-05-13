#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&d) {
    for (int x : d) cout<<x<<' ';
    cout<<'\n';
}

bool allZero(vector<int>&d) {
    for (int x : d)
        if (x!=0) return false;
    return true;
}

bool check(vector<int>&d) {
    long long sum=0;
    for(int x : d) sum+=x;
    if (sum%2!=0) return false;
    int cur = d[0];
    while (true) {
        sort(d.begin(), d.end(), greater<int>());
        print(d);
        cur = d[0];
        if (d[cur]==0) return false;
        d.erase(d.begin());
        if (cur > (int)d.size()) return false;
        for (int i=0; i<cur; i++) d[i]--;
        if (allZero(d)) {
            print(d);
            return true;}
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int>d(n);
        for(int i=0; i<n; i++) cin>>d[i];
        cout<<"\n-----------------------------\n";
        if(check(d)) cout<<1<<'\n';
        else cout<<0<<'\n';
        cout<<"\n-----------------------------\n";
    }
}