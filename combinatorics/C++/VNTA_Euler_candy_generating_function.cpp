//Euler inclusive-exclusive vs. generating function
#include <bits/stdc++.h>
using namespace std;

//inclusion-exclusion
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

long long countSolutionsInEx(int m, int n, vector<int>& lower, vector<int>& upper) {
    int sum_lower=0;
    for (int i=0; i<n; i++) {
        sum_lower+=lower[i];
    }
    int m1 = m-sum_lower;
    if (m1<0) return 0;

    vector<int> b(n);
    for (int i=0; i<n; i++) {
        b[i]=upper[i]-lower[i];
    }

    long long res=0;
    for (int mask=0; mask<(1<<n); mask++) {
        int sign=(__builtin_popcount(mask)%2==0) ? 1 : -1;
        int new_m=m1;
        for (int i=0; i<n; i++) {
            if (mask & (1<<i)) {
                new_m-=(b[i]+1);
            }
        }
        res += sign*nCr(new_m+n-1, n-1);
    }
    return res;
}

void genSolution(vector<int>& x, vector<int>& lower, vector<int>& upper, int m, int n, int pos, int sum, vector<vector<int>>& solutions) {
    if (pos==n-1) {
        int remaining=m-sum;
        if (remaining>=lower[pos] && remaining<=upper[pos]) {
            x[pos]=remaining;
            solutions.push_back(x);
        }
        return;
    }

    for (int i=lower[pos]; i<=min(upper[pos], m-sum); i++) {
        x[pos]=i;
        genSolution(x, lower, upper, m, n, pos+1, sum+i, solutions);
    }
}

//generating function
vector<long long> poly(const vector<long long>&p, int start, int end, int maxDegree) {
    vector<long long> res(maxDegree+1, 0);
    for (int i=0; i<p.size(); i++) {
        if (p[i] == 0) continue;
        for (int j=start; j<=end && i+j<=maxDegree; j++) {
            res[i+j]+=p[i];
        }
    }
    return res;
}

long long countSolutionsGenFunc(int m, int n, vector<int>& lower, vector<int>& upper) {
    vector<long long> p(m+1, 0);
    p[0]=1;
    for (int i=0; i<n; i++) {
        p=poly(p,lower[i],upper[i],m);
    }
    return p[m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin>>m>>n;
    vector<int> lower(n), upper(n);
    for (int i=0; i<n; i++) cin>>lower[i];
    for (int i=0; i<n; i++) cin>>upper[i];

    int min_sum = 0, max_sum = 0;
    for (int i=0; i<n; i++) {
        min_sum+=lower[i];
        max_sum+=upper[i];
        if (lower[i]>upper[i]) {
            cout<<"0";
            return 0;
        }
    }
    if (m<min_sum || m>max_sum) {
        cout<<"0";
        return 0;
    }

    long long num_solutions_1=countSolutionsInEx(m,n,lower,upper);
    cout<<"Ket qua tinh ra (inclusion-exclusion): "<<num_solutions_1<<'\n';

    long long num_solutions_2=countSolutionsGenFunc(m,n,lower,upper);
    cout<<"Ket qua tinh ra (generating function): "<<num_solutions_2<<'\n';

    vector<int> x(n, 0);
    vector<vector<int>> solutions;
    genSolution(x, lower, upper, m, n, 0, 0, solutions);

    cout<< "So bo nghiem generate ra: " <<solutions.size()<<'\n';
    for (const auto& sol : solutions) {
        for (int i=0; i<n; i++) {
            cout<<sol[i];
            if (i < n-1) cout << " ";
        }
        cout<<'\n';
    }
    return 0;
}

/*
Input
20 5
2 1 3 0 1
9 5 10 2 3
Output: 260

Input:
30 7
2 1 0 3 1 2 1
4 3 10 5 3 8 3
Output: 514
*/