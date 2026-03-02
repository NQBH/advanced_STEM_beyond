#include <iostream>
#include <cmath>
using namespace std;
int main () {
   double a1, b1, c1;
   double a2, b2, c2;
   cout << " Nhap vao he so  a1,b1,c1 (phuong trinh 1):";
   cin >> a1 >> b1 >> c1;
   cout << " Nhap vao he so  a2,b2,c2 (phuong trinh 2):";
   cin >> a2 >> b2 >> c2;
   double D = a1 * b2 - a2 * b1;
   double Dx = c1 * b2 - c2 * b1;
   double Dy = a1 * c2 - a2 * c1;
   if ( D != 0 ) {
      double x = Dx / D;
      double y = Dy / D;
      cout <<  " He phuong trinh co nghiem duy nhat " << endl;
      cout << "x" << x << endl;
      cout << "y" << y << endl;
   }
   else if
   ( Dx != 0 || Dy != 0) {
      cout << " Phuong trinh vo nghiem " << endl;
   }
   else {
      cout << " Phuong trinh co vo so nghiem " << endl;
   }
   return 0;
}