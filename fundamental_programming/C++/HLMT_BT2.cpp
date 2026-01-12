
#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
    const float chieudai =3;
    const float chieurong =4;
    float Chuvi = 2 * (chieudai+chieurong);
    float Dientich = chieudai * chieurong;
    float Duongcheo = sqrt(chieudai * chieudai+chieurong * chieurong);
    
    cout << "Chu vi hinh chu nhat la: " << Chuvi << endl;
    cout << "Dien tich hinh chu nhat la: " << Dientich << endl;
    cout << "Do dai duong cheo la: " << Duongcheo << endl;
    
    
    return 0;
}