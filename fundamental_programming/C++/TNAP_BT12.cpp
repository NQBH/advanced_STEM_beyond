#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, m;
   double sum = 0;
   cin >> n >> m;
   for ( int i = 1; i <= n; i++) {
      sum  += pow(i, m);
   } cout << "Tong Sm =" << sum;
}