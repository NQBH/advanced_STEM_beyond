#include<bits/stdc++.h>
using namespace std ;
int main () {
   int a , b , x ; cin >> a >> b ;
   if (a = 0 ) {
      if (b = 0 ) {
         cout << "PT vo so nghiem" << endl ;
      }
      else {
         cout << "PT vo nghiem" << endl ;
      }
   }
   else {
      if (a % b == 0) {
         int x = -b / a ;
         cout << x << endl ;
      }
      else {
         cout << "PT vo nghiem" << endl ;
      }
   }


}






