#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    while (true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        if (ss.str().empty() == 1) {break;}
        double x1, y1, x2, y2, x3, y3;
        int i = 1, mark;
        while (i <= 6) {
            string temp, cur = "", next = "";
            ss >> temp;
            int j = 0;
            if (temp[0] < '0' || temp[0] > '9') {mark = -1; ++j;}
            else {mark = 1;}
            for (j; j < temp.size(); ++j) {
                if (temp[j] == '.') {break;}
                if (temp[j] < '0' || temp[j] > '9') {continue;}
                cur = cur + temp[j];
            }
            ++j;
            int yeah = temp.size() - j;
            for (j; j < temp.size(); ++j) {
                next = next + temp[j];
            }
            double alter, another = 0;
            stringstream sss(cur);
            //stringstream ssss(next);
            sss >> alter;
            //ssss >> another;
            for (int k = yeah; k >= 1; --k) {
                another += (next[k - 1] - '0') * (1 / pow(10, k));
            }
            alter += another;
            alter *= mark;
            switch (i) {
            case 1: x1 = alter; break;
            case 2: y1 = alter; break;
            case 3: x2 = alter; break;
            case 4: y2 = alter; break;
            case 5: x3 = alter; break;
            case 6: y3 = alter; break;
            }
            ++i;
        }

        double a = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
        double b = sqrt(abs(x1 - x3) * abs(x1 - x3) + abs(y1 - y3) * abs(y1 - y3));
        double c = sqrt(abs(x2 - x3) * abs(x2 - x3) + abs(y2 - y3) * abs(y2 - y3));
        double P = a + b + c;
        double p = P / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        double r = a * b * c / 4 / S;
        double cir_cu = 2 * r * M_PI;
        cout << fixed << setprecision(2) << cir_cu << el
    }
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
