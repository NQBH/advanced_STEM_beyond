#include <iostream>
#include <vector>
using namespace std;

int main () {

//---Problem 1---
   double a, b, c;
   double min, max;
   cout << "Nhap 3 so thuc a, b, c:" << endl;
   cin >> a >> b >> c;

   //-min-
   if ( a <= b && a <= c ) {
      min = a;
   }
   else if ( b <= a && b <= c ) {
      min = b;
   }
   else {
      min = c;
   }

   //-max-
   if ( a >= b && a >= c) {
      max = a;
   }
   else if ( b >= a && b >= c ) {
      max = b;
   }
   else {
      max = c;
   }

   cout << "Max = " << max << endl;
   cout << "Min = " << min << endl;

//---Problem 2---
   double n;
   cout << "Nhap so phan tu cua n:" << endl;
   cin >> n;

   vector<double> arr(n);

   for (int i = 0; i < n; i++) {
      cout << "nhap so: ";
      cin >> arr[i];
   }

   //min max
   double vmax = arr[0];
   double vmin = arr[0];

   for (int i = 0; i < n; i++) {
      if (vmax < arr[i] ) {
         vmax = arr[i];
      }

      if (vmin > arr[i]) {
         vmin = arr[i];
      }
   }

   cout << "min: " << vmin << endl;
   cout << "max: " << vmax << endl;

}