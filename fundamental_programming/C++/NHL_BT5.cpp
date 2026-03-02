#include <cmath>
#include <iostream>
using namespace std;
int main()
{
  double a, b, x;
  cout << "nhập số a và b: " << '\n';
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  double s = (a * x + b == 0);
  if (a != 0) {
    x = -b / a;
    cout << "phương trình có nghiệm là: " << x ;
  }
  else {
    if  (b == 0)
      cout << "phương trình vô số nghiệm";
    else
      cout << "phương trình vô nghiệm ";

  }

}