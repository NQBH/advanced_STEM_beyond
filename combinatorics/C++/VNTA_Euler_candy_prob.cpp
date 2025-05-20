//a, b
#include <bits/stdc++.h>
using namespace std;

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

void genSolution(vector<int>& x, vector<int>& s, int m, int n, int pos, int sum, vector<vector<int>>& solutions) {
    if (pos==n-1) {
        int remaining=m-sum;
        if (s[pos]==1 && remaining>=1) {
            x[pos]=remaining;
            solutions.push_back(x);
        } else if (s[pos]==0 && remaining>=0) {
            x[pos]=remaining;
            solutions.push_back(x);
        }
        return;
    }

    int start=(s[pos]==1) ? 1 : 0;
    for (int i=start; i<=m-sum; i++) {
        x[pos]= i;
        genSolution(x, s, m, n, pos+1, sum+i, solutions);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n, d=0;
    cin>>m>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++) {
        cin>>s[i];
        if(s[i]>0) d++;
    }
    if (m<d) {
        cout<<0;
        return 0;
    }
    long long res=nCr((m-d)+n-1, n-1);
    cout<<"Ket qua tinh ra: "<<res<<'\n';
    vector<int> x(n,0);
    vector<vector<int>> solutions;
    genSolution(x, s, m, n, 0, 0, solutions);
    cout<<"So bo nghiem generate ra: "<<solutions.size()<<'\n';
    for (const auto& sol : solutions) {
        for (int i=0; i<n; i++) {
            cout<<sol[i];
            if (i < n-1) cout << " ";
        }
        cout<<'\n';
    }
    return 0;
}