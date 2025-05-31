#include<bits/stdc++.h>
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
#define pops pop_back
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

SORAI{
    //Sanic_speed
    double long ans = 0;
    int p = 0;
    cout << "Nhap x0 (inf/-inf/{1 so bat ki}): ";
    int m, n;
    string x, ans2;
    cin >> x;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap day tu a[0] den a[m]: ";
    int a[m + 1], b[n + 1];
    fre(i, 0, m) {
        cin >> a[i];
    }
    cout << "Nhap day tu b[0] den b[n]: ";
    fre(i, 0, n) {
        cin >> b[i];
    }
    int situ;
    if (x.size() > 1) {
        if (x[0] == 'i' || x[1] == 'i') { situ = 1; }
        else { situ = 2; }
    }
    else { situ = 2; }
    if (situ == 1) {
        if (m == n) {
            ans = (a[m] * 1.0 / (b[n] * 1.0));
        } elif(m > n) {
        ans2 = x;
        p = 1;
    }
    else {
    ans = 0;
    }
}
else {
 int newx = 0;
 frs(i, 0, x.size()) {
     if (x[i] == '-') { ++i; }
     newx *= 10;
     newx += (x[i] - '0');
 }
 if (x[0] == '-') { newx *= -1; }
 ll nume = a[0], deno = b[0], nums = 1, dens = 1;
 fre(i, 1, m) {
     nums *= newx;
     nume += (nums * a[i]);
 }
 fre(i, 1, n) {
     dens *= newx;
     deno += (dens * b[i]);
 }
 if (nume == 0) {
     if (deno == 0) {
         nume = a[1]; deno = b[1], nums = 1, dens = 1;
         fre(i, 2, m) {
             nums *= newx;
             nume += (nums * a[i] * i);
         }
         fre(i, 2, n) {
             dens *= newx;
             deno += (dens * b[i] * i);
         }
         ans = (1.0 * nume / (deno * 1.0));
     }
else { ans = 0; }
} elif(deno == 0) {
    cout << "Chua biet code truong hop nay :(" << el
    cout << "Truong hop nay la dang: C/0 (C != 0)" << el
    cout << "Nhan xet voi 2 truong hop la x+ va x-" << el
    cout << "Neu cung ra inf thi = inf" << el
    cout << "Neu cung ra -inf thi = -inf" << el
    cout << "Neu ra moi cai inf va -inf thi = Non-exist" << el
    Ret
}
else { ans = (nume * 1.0 / (deno * 1.0)); }
}
if (p == 1) {
    cout << "Ket qua: " << ans2;
}
else { cout << "Ket qua: " << ans; }
}
