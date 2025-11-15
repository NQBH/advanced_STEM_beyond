#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
#include<set>
#include<iomanip>
#define F first
#define S second
#define P system("PAUSE");
#define H return 0;
#define pb push_back
using namespace std;
const long long A = 100000000000000LL, N = 228228;

long long a[N], k, o, i, j, n, m;

int main() {
    cin >> n;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    k = 1;
    for (i = 1; i < n; i++) if (a[i] >= a[i - 1]) k++; else o = max(o, k), k = 1;
    o = max(o, k);
    cout << o;
}