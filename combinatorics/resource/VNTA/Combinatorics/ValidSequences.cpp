#include<bits/stdc++.h>
using namespace std;

long long total = 0;

long long nCk(int n, int k) {
    if (k>n||k<0) return 0;
    long long res=1;
    for(int i=1; i<=k; i++) {
        res*=(n-i+1);
        res/=i;
    }
    return res;
}

void generateSeq(int n, int m, int pos, int last, vector<int>& seq, int cnt0, int cnt1) {
    if (cnt0>m || cnt1>n-m) return;
    if (pos==n) {
        if(cnt0==m && cnt1==n-m) {
            for(int x:seq) cout<<x<<" ";
            cout<<"\n";
            total++;
        }
    }

    seq.push_back(1);
    generateSeq(n, m, pos+1, 1, seq, cnt0, cnt1+1);
    seq.pop_back();

    if(last!=0) {
        seq.push_back(0);
        generateSeq(n, m, pos+1, 0, seq, cnt0+1, cnt1);
        seq.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> seq;
    generateSeq(n, m, 0, -1, seq, 0, 0);
    cout<<"Tong so day hop le: "<<total<<"\n";
    cout<<"(n-m+1)Cm = "<<nCk(n-m+1, m);
}
