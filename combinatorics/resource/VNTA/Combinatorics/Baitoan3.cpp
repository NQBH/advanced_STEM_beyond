#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

bool ktcp(int x) {
    int r=(int)round(sqrt((double)x));
    return r*r==x;
}

bool checkSet(const vector<int>& s) {
    int n=s.size();
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                int prod=s[i]*s[j]*s[k];
                if (ktcp(prod)) return false;
            }
        }
    }
    return true;
}

int main() {
    KhangGPT40_TramAnhGrok3;
    vector<int>u(15);
    iota(u.begin(),u.end(),1);
    bool f=false;
    vector<bool> bitmask(15, false);
    fill(bitmask.begin(), bitmask.begin()+10, true);
    cout<<"=== Cau a ===\n";
    do {
        vector<int>s;
        for(int i=0; i<15; i++) {
            if(bitmask[i]) s.push_back(u[i]);
        }
        if (checkSet(s)) {
            f=true;
            for(int x : s) cout<<x<< " ";
            cout<<"\n";
        }
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    if(!f) {
        cout<<"Khong tim thay tap hop thoa de\n";
    }

    cout<<"=== Cau b ===\n";
    for (int i=15; i>=1; i--) {
        vector<bool> bitmask(15, false);
        fill(bitmask.begin(), bitmask.begin()+i, true);
        do {
            vector<int> s;
            for (int j=0; j<15; j++) {
                if (bitmask[j]) s.push_back(j+1);
            }
            if (checkSet(s)) {
                cout<<"Max size = "<<i<<"\n";
                for(int x : s) cout<<x<< " ";
                return 0;
            }
        } while (prev_permutation(bitmask.begin(), bitmask.end()));
    }
    return 0;
}
