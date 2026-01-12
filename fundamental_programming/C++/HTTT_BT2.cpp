#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const float dai=9;
    const float rong=4;
    float Chuvi, Dientich, Duongcheo;
    
    Chuvi = (dai+rong)*2;
    Dientich = dai*rong;
    Duongcheo = sqrt(dai*dai+rong*rong);
    
    cout << "Chuvi hinh chu nhat la: "<<Chuvi <<endl;
    cout << "Dien tich hinh chu nhat la: "<<Dientich <<endl;
    cout << "Duongcheo hinh chu nhat la: "<< Duongcheo <<endl;

    return 0;
}