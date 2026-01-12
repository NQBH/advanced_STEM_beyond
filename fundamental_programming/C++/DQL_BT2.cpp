#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float a, b;
  float ChuVi, DienTich, DuongCheo;

  cout << "Nhap chieu dai hinh chu nhat: ";
  cin >> a;
  cout << "Nhap chieu rong duong chu nhat: ";
  cin >> b;

  ChuVi = ( a + b ) * 2;
  DienTich = a * b;
  DuongCheo = sqrt(a * a + b * b);


  cout << "Chu vi hinh chu nhat la: " << ChuVi << endl;
  cout << "Dien tich hinh chu nhat la: " << DienTich << endl;
  cout << "Do dai duong cheo la: " << DuongCheo << endl;
  return 0;
}