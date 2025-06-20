/*
Source: ACM Beijing 2004, Preliminary.
IDs for online judges: POJ 1922, ZOJ 2229.
Status: Accepted
*/
#include <iostream>
#include <vector>
using namespace std;

struct driver {
    double v;
    double t;
};

int main(){
    int n;
    const double distance = 4500; 
    while(cin >> n && n != 0) {
        vector<driver> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].v >> a[i].t;
            a[i].v = a[i].v * 1000 / 3600;
        }
        double min_dist = 1e9 + 7;
        for (int i = 0; i < n; ++i)
            if (a[i].t >= 0)
                min_dist = min(min_dist,distance / a[i].v + a[i].t); 
        int ans = (int)min_dist + (min_dist == (int)min_dist ? 0 : 1);
        cout << ans << endl;
    }
}