#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3010;
const int LOGN = 28;
const ll  TMD = 0;
const ll  INF = 100000000;
int T, n, m;
int cnt[N], mxr[N];
int dp[N][N][2];

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

//--------------------------------------------------------------------------

struct seg
{
    int l, r;

    seg() {}

    seg(int l, int r): l(l), r(r) {}

    int len()
    {
        return r - l + 1;
    }
};

seg getins(seg x, seg y)
{
    if (x.l > y.l) swap(x, y);
    if (x.r < y.l) return seg(INF, INF);
    if (x.r < y.r) return seg(y.l, x.r);
    else return seg(y.l, y.r);
}

//--------------------------------------------------------------------------

void init()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        cnt[i] = mxr[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        mxr[l] = max(mxr[l], r);
    }
    for (int i = 0; i <= n + 4; i++)
        for (int j = 0; j <= n + 4; j++)
            dp[i][j][0] = dp[i][j][1] = -INF;
}

void solve()
{
    int sz, cfree = 0;
    vector<int> tag(n + 4);
    vector<seg> vs;
    for (int i = 1; i <= n; i++)
    {
        if (!mxr[i]) continue;
        if (vs.empty() || vs.back().r < mxr[i])
            vs.push_back(seg(i, mxr[i]));
    }
    sz = vs.size();
    dp[1][0][0] = vs[0].len();
    dp[1][vs[0].len()][1] = 0;
    for (int i = 2; i <= sz; i++)
    {
        seg cur = vs[i - 1], ins = getins(vs[i - 2], vs[i - 1]);
        int len_ins = (ins.l == INF ? 0 : ins.len());
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + cur.len() - len_ins);
            if (j + len_ins <= n)
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j + len_ins][1] + cur.len() - len_ins);
            if (j - (cur.len() - len_ins) >= 0)
            {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - (cur.len() - len_ins)][1]);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - (cur.len() - len_ins)][0] - len_ins);
            }
        }
    }
    for (int i = 0; i < vs.size(); i++)
        for (int j = vs[i].l; j <= vs[i].r; j++)
            tag[j] = 1;
    for (int i = 1; i <= n; i++)
        if (!tag[i]) cfree++;
    if (cfree >= cnt[0])
    {
        cout << "0\n";
        return ;
    }
    for (int i = 1, mn = cnt[0]; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int need1 = max(0, mn - j), need2 = max(0, cnt[i] - max(dp[sz][j][0], dp[sz][j][1]));
            if (cfree >= need1 + need2)
            {
                cout << i << "\n";
                return ;
            }
        }
        mn = min(mn, cnt[i]);
    }
}

//-------------------------------------------------------

void gen_data()
{
    srand(time(NULL));
}

int bruteforce()
{
    return 0;
}

//-------------------------------------------------------

int main()
{
    fastio;

    cin >> T;
    while (T--)
    {
        init();
        solve();

        /*

        //Stress Test

        gen_data();
        auto ans1=solve(),ans2=bruteforce();
        if(ans1==ans2) printf("OK!\n");
        else
        {
            //Output Data
        }

        */
    }

    return 0;
}
// WA test 1 CF