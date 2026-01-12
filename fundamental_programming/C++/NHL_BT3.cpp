
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
  int a ;
  int b ;
  int c ;
  cout << "nhap so a " << '\n';
  cin >> a ;
  cout << "nhap so b " << '\n';
  cin >> b ;
  cout << "nhap so c " << '\n';
  cin >> c ;
  if (a > 0 && b > 0 && c > 0 && a == b && b == c)
    cout << "HLP";
  else if (a > 0 && b > 0 && c > 0 ) {
    cout << "HHCN" << '\n';
    int xq = 2 * c * (a + b);
    int tp = 2 * (a * b + a * c + b * c);
    float dc = sqrt(a * a + b * b + c * c);
    int tt = a * b * c ;
    cout << "dien tich xung quanh cua hhcn: " << xq << '\n';
    cout << "dien tich toan phan  cua hhcn: " << tp << '\n';
    cout << "duong cheo cua hhcn: " << dc << '\n';
    cout << "the tich cua hhcn: " << tt << '\n';
  }
  else {
    cout << -1;
  }
}