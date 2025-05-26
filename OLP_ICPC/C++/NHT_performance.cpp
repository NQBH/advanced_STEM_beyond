#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct egde{
    int s, t, c;
}a[1000005];

bool cmp(egde x, egde y){
    return x.t < y.t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--){
        int m, n;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i].s >> a[i].t >> a[i].c;
        sort(a, a + m, cmp);

        ll ans = 0;
        int cur = 0;

        while(cur < n){
            int bestCost = INT_MAX, nextPos = cur;
            for(const auto& edge : a){
                if(edge.s <= cur && cur < edge.t){  
                    if(edge.c < bestCost){
                        bestCost = edge.c;
                        nextPos = edge.t;
                    }
                }
            }
            if(bestCost == INT_MAX){
                ans = -1;
                break;
            }
            ans += bestCost;
            cur = nextPos;
        }
        cout << ans << endl;
    }
    return 0;
}