#include<bits/stdc++.h>
using namespace std;

void generateSubsets(int n, int idx, int &cnt, vector<int>& subset) {
    if (idx>n) {
        cout<<"{";
        for(int ele : subset) cout<<ele<<" ";
        cout<<"}\n";
        cnt++;
        return;
    }
    generateSubsets(n, idx+1, cnt, subset);
    subset.push_back(idx);
    generateSubsets(n, idx+1, cnt, subset);
    subset.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> subset;
    int cnt=0;
    generateSubsets(n, 1, cnt, subset);
    cout<<"So tap con cua [n]: "<<cnt<<"\n";
    cout<<"2^n = "<<(1<<n)<<"\n";
}
