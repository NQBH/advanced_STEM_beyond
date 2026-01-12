#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double x ;
   cout << "Nhap x: " ;
   cin >> x ;

   if (x >= 0) {
      // sqrt
      cout << "sqrt " << sqrt (x ) << endl ;
      // pow
      cout << "pow " << pow (x, 2) << endl ;
      // log
      cout << "log " << log (x ) << endl ;
      // exp
      cout << "exp " << exp (x ) << endl ;
      // log10
      cout << "log10 " << log10 (x ) << endl ;
      // int
      int absX = abs (x) ;
      cout << "abs(int x) " << absX << endl ;
      // long
      long labsX = labs (x) ;
      cout << "labs (int x) " << labsX << endl ;
      // double
      double fabsX = fabs (x) ;
      cout << "fabs (int x) " << fabsX << endl ;
      // sin
      double pi = acos (-1.0) ;
      double rad = pi / 6 ; // 30 do
      cout << "sin " << sin (rad) << endl ;
      // cos
      cout << "cos " << cos (rad) << endl ;
      // tan
      cout << "tan " << tan (rad) << endl ;
      // asin
      cout << "asin " << asin (0.5) << endl ;
      // acos
      cout << "acos " << acos (0.5) << endl ;
      // atan
      cout << "atan " << atan (0.5) << endl ;
      // floor
      double z = 3.7 ;
      cout << "floor " << floor (z) << endl ;
      // ceil
      cout << "ceil " << ceil (z) << endl ;
   }
   return 0 ;
}