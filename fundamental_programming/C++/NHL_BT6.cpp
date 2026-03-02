#include <cmath>
#include <iostream>
using namespace std;
int main()
{
  double a, b, c, x;
  cout << "nhập số a,b,c: " << '\n';
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  cout << "c: ";
  cin >> c;
  if (a == 0) {
    if (b == 0) {
      if (c == 0)

        cout << "phương trình vô số nghiệm";
      else
        cout << "phương trình vô nghiệm";
    }
    else {
      x = -c / b;
      cout << "phương trình bậc nhất có nghiệm: " << x;

    }
  }
  else
  {

    double denta = b * b - 4 * a * c;
    if (denta == 0) {
      x = -b / (2 * a);
      cout << "phương trình có nghiệm kép x: " << x;
    }
    else {
      if (denta < 0)
        cout << "phương trình vô nghiệm thực";
      else
      { double x1 = (-b + sqrt(denta)) / (2 * a);
        double x2  = (-b - sqrt(denta)) / (2 * a);
        cout << "phương trình có 2 nghiệm thực" << '\n';
        cout << "x1 = " << x1 << '\n' ;
        cout << "x2 = " <<  x2;

      }
    }
  }
}