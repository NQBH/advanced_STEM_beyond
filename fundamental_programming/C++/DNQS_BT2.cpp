#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    float C, S, dientich, duongcheo ;
    float chieudai;
    float chieurong;
    cout << "nhap chieu dai" ;
    cin >> chieudai ;
    cout << "nhap chieu rong";
    cin >> chieurong ;
    C = 2 * (chieudai + chieurong);
    S = chieudai * chieurong ;
    duongcheo = sqrt(pow(chieudai, 2) + pow(chieurong, 2));
    cout << "chu vi = " << C << endl ;
    cout << "dien tich = " << S << endl ;
    cout << "duongcheo = " << duongcheo << endl ;
    return 1 ;
}