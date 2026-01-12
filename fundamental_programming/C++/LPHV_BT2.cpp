#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  float chieudai;
  cout << "Nhap chieu dai cua hinh chu nhat: ";
  cin >> chieudai;
  float chieurong;
  cout << "Nhap chieu rong cua hinh chu nhat: ";
  cin >> chieurong;
  float C = (chieudai + chieurong) * 2;
  cout << "Chu vi cua hinh chu nhat la " << C << '\n';
  float S = chieudai * chieurong;
  cout << "Dien tich cua hinh chu nhat la " << S << '\n';
  double duongcheo = sqrt(chieudai * chieudai + chieurong * chieurong);
  cout << "Do dai duong cheo cua hinh chu nhat la " << duongcheo << '\n';
}
