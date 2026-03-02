#include <iostream>
using namespace std;
int main()
{
  double a, b, c, A, B, C;
  cout << "nhập a: ";
  cin >> a;
  cout << "nhập b: ";
  cin >> b;
  cout << "nhập c: ";
  cin >> c;
  cout << "nhập A: ";
  cin >> A;
  cout << "nhập B: ";
  cin >> B;
  cout << "nhập C: ";
  cin >> C;
  if (a * B - b * A != 0) {
    double x, y;
    x = (c * B - b * C) / (a * B - b * A);
    y = (a * C - c * A) / (a * B - b * A);
    cout << "hệ có nghiệm duy nhất:" << '\n';
    cout << "x: " << x << '\n';
    cout << "y: " << y;
  }
  else {
    if (a * C == c * A) {
      cout << "hệ có vô số nghiệm";

    }
    else {
      cout << "hệ vô nghệm";

    }
  }
}