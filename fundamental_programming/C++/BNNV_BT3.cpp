#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int a,b,c;
    cout << "Nhap gia tri cua a, b, c = " << endl;
    cin >> a >> b >> c;
    
    if( a <= 0 || b <= 0 || c <= 0) {
       cout << "Gia tri khong hop le" << endl; 
       return 0;
    } 
    else if ( a == b && b == c ) {
       cout << "HLP" << endl;
    }
    else {
       cout << "HHCN" << endl;
    }
    cout << "Dien tich xung quanh hinh hop chu nhat: " << 2 * (a + b) * c << endl;
    cout << "Dien tich toan phan hinh hop chu nhat: " << 2 * (a * b + a * c + b * c) << endl;
    cout << "Duong cheo hinh hop chu nhat: " << sqrt(a * a + b * b + c * c) << endl;
    cout << "The tich hinh hop chu nhat: " << a * b * c << endl;
    
    return 0;
    
}
    