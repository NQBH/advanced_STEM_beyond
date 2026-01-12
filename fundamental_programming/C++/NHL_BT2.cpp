#include <cmath>
#include <iostream>
using namespace std;
int main()
{
  float d;
  float r;
  cout << "nhap chieu dai hinh chu nhat: " << '\n';
  cin >> d ;
  cout << "nhap chieu rong hinh chu nhat: " << '\n';
  cin >> r;
  float n = d * r;
  float e = (d + r) * 2;
  float daixdai = d * d;
  float rongxrong = r * r;
  float t = sqrt(daixdai + rongxrong);
  cout << "dien tich hinh chu nhat: " << n << '\n';
  cout << "chu vi hinh chu nhat: " << e << '\n';
  cout << "duong cheo hinh chu nhat: " << t << '\n';
}