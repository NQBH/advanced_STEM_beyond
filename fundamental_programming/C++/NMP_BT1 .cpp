#include <iostream>
using namespace std;
int main() {
  float CanhHinhVuong;
  cout << "nhap do dai hinh vuong: ";
  cin >> CanhHinhVuong;

  float ChuVi = 4 * CanhHinhVuong;
  float DienTich = CanhHinhVuong * CanhHinhVuong;
  cout << "chu vi hinh vuong: " << ChuVi << endl;
  cout << "dien tich hinh vuong: " << DienTich << endl;
  return 0;
}