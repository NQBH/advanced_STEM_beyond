#include <cmath>
#include <iostream>
using namespace std;
int main()
{
   int cd, cr;
   cout << " Nhap chieu dai :";
   cin >> cd;
   int cv, dt, dc;
   cout << " Nhap chieu rong :";
   cin >> cr;
   cv = 2 * (cd + cr);
   dt = cd * cr;
   dc = sqrt(cd * cd + cr * cr);
   cout << " chu vi hcn la: " << cv;
   cout << " dien tich hcn la: " << dt;
   cout << " duong cheo hcn la: " << dc;
   return 0;
}