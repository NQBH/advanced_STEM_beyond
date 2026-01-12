/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
   float ChieuDai, ChieuRong;
   cout << "nhap chieu dai hinh chu nhat: ";
   cin >> ChieuDai;
   cout << "nhap chieu rong hinh chu nhat: ";
   cin >> ChieuRong;

   float ChuVi = 2 * ( ChieuDai + ChieuRong );
   float DienTich = ChieuDai * ChieuRong;
   float DoDaiDuongCheo = sqrt ( ChieuDai * ChieuDai + ChieuRong * ChieuRong);

   cout << "chu vi hinh chu nhat: " << ChuVi << endl;
   cout << "dien tich hinh chu nhat: " << DienTich << endl;
   cout << "do dai duong cheo hinh chu nhat: " << DoDaiDuongCheo << endl;
   return 0;

}