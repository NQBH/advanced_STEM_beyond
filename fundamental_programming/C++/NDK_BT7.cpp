#include <iostream>
#include <cmath>
using namespace std;
int main () {
   double a, b, c;
   cout << " Nhap 3 so thuc a,b,c";
   cin >> a >> b >> c;
   double maxVal = a;
   if ( b > maxVal) {
      maxVal = b;
   }
   if ( c > maxVal) {
      maxVal = c;
   }
   double minVal = a;
   if ( b < minVal ) {
      minVal = b;
   }
   if ( c < minVal ) {
      minVal = c;
   }
   cout << "So lon nhat la:" << maxVal << endl;
   cout << "So nho nhat la:" << minVal << endl;
   return 0;
}