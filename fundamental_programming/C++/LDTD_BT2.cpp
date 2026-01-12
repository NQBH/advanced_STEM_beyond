#include <iostream>
#include <cmath> // Cần thư viện này để dùng hàm sqrt (căn bậc 2)
using namespace std;

int main() {
// Khai báo biến kiểu float để chứa số thực (có dấu phẩy)
  float duongcheo, chuvi, dientich;
  // canh hinh chu nhat //
  int a = 2 ;
  int b = 4 ;
  // tinh chu vi hinh chu nhat C = ( a + b) * 2;
  // tinh dien tich hinh chu nhat  S = a * b ;
  // tinh duong cheo cua hinh chu nhat d = sqrt ( a * a + b * b)'
  cout << " nhap chieu dai a : ";
  cin >> a ;
  cout << " nhap chieu rong b : ";
  cin >> b ;

  chuvi = ( a + b ) * 2;
  dientich = ( a + b );
  duongcheo = sqrt (a * a + b * b);

  cout << "\nChu vi hinh chu nhat: " << chuvi << endl;
  cout << "Dien tich hinh chu nhat: " << dientich << endl;
  cout << "Duong cheo hinh chu nhat: " << duongcheo << endl;
  return 0;
}