
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    const float a =2;
    const float b =3;
    const float c =4;
    
    // Kiem tra hinh lap phuong 
    if (a == b && b == c && a > 0 ) {
        cout << "HLP";
    }
    
    // Kiem tra hinh hop chu nhat 
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;
        
        int dientichXQ = 2 * c * (a+b);
        int dientichTP = 2 * (a*b + a*c + b*c);
        float duongcheo = sqrt(a*a + b*b + c*c);
        int thetich = a * b * c;
        
        cout << "Dien tich xung quanh: " << dientichXQ << endl;
        cout << "Dien tich toan phan: " << dientichTP << endl;
        cout << "Duong cheo: " << duongcheo << endl;
        cout << "The tich: " << thetich << endl;
    }
    // Khong phai hinh hop chu nhat
    else {
        cout << -1;
        
    }
    return 0;
}