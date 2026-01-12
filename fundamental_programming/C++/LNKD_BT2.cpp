#include <cmath>
#include <iostream>
using namespace std;
      int main() {
         float ChieuDai, ChieuRong;
         cout << "nhap chieu dai hinh chu nhat: ";
         cin >> ChieuDai;
         cout << "nhap chieu rong hinh chu nhat: ";
         cin >> ChieuRong;
         
         float ChuVi = 2 * ( ChieuDai+ ChieuRong );
         float DienTich = ChieuDai * ChieuRong;
         float DoDaiDuongCheo = sqrt ( ChieuDai * ChieuDai + ChieuRong * ChieuRong);
         
         cout << "chu vi hinh chu nhat: " << ChuVi << endl;
         cout << "dien tich hinh chu nhat: " << DienTich << endl;
         cout << "do dai duong cheo hinh chu nhat: " << DoDaiDuongCheo << endl;
          return 0;
      }