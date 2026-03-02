#include <bits/stdc++.h>
using namespace std ;
int main ()
{
   float a, b, c;
   int max;
   int min;
   cin >> a >> b >> c;
   if (a > b) {
      max = a ;
   }
   else if (a > c) {
      max = a ;
   }
   else {
      if (b > c) {
         max = b ;
      }
      else {
         max = c ;
      }
   }
   if (a < b) {
      min = a ;
   }
   else if (a < c) {
      min = a ;
   }
   else {
      if (b < c) {
         min = b ;
      }
      else {
         min = c ;

      }
   }
   cout << max << " " << min ;
}