
#include <iostream>
using namespace std;

int main() {
   double a, b, c, A, B, C;
   cout << "Nhap he so a cua phuong trinh 1: " ;
   cin >> a;
   cout << "Nhap he so b cua phuong trinh 1: " ;
   cin >> b;
   cout << "Nhap he so c cua phuong trinh 1: " ;
   cin >> c;
   cout << "Nhap he so A cua phuong trinh 2: " ;
   cin >> A;
   cout << "Nhap he so B cua phuong trinh 2: " ;
   cin >> B;
   cout << "Nhap he so C cua phuong trinh 2: " ;
   cin >> C;

   double D   = a * B - A * b;

   double Dx   = c * B - C * b;
   double Dy   = a * C - A * c;

   if ( D != 0 ) {
      cout << "Nghiem duy nhat x = " << Dx / D << ", y = " << Dy / D << '\n';
   } else if (Dx == 0 && Dy == 0) {
      cout << "Vo so nghiem" << endl;
   } else {
      cout << "Vo nghiem " << endl;
   }
   return 0;
}
