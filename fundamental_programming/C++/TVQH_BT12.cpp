#include <iostream>
#include <cmath>
using namespace std;
int main () {
   int n, m;
   double s = 0;
   cout << "Nhap n va m:";
   cin >> n >> m;
   int i;
   for (i = 1; i <= n ; i++) {
      s = s + pow(i, m);

   }
   cout << "S = " << s;
   return 0;
}
