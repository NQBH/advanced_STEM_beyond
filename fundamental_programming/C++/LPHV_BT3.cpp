#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int a;
  cout << "Nhap a: ";
  cin >> a;
  int b;
  cout << "Nhap b: ";
  cin >> b;
  int c;
  cout << "Nhap c: ";
  cin >> c;
  if (a > 0 && b > 0 && c > 0)
  {
    if (a == b && b == c)
    {
      cout << "HLP" << '\n';
    }
    else
    {
      cout << "HHCH" << '\n';
      int Sxq = 2 * (a + b) * c;
      cout << "Dien tich xung quanh: " << Sxq << '\n';
      int Stp = 2 * (a * b + a * c + b * c);
      cout << "Dien tich toan phan: " << Stp << '\n';
      double d = sqrt(a * a + b * b + c * c);
      cout << "Do dai duong cheo: " << d << '\n';
      int V = a * b * c;
      cout << "The tich: " << V << '\n';
    }
  }
  else
  {
    cout << -1;
  }
}
