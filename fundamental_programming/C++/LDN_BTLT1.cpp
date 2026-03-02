#include <iostream>
#include <cmath>    
using namespace std;

int main() {
    int a, n;
    cout << "Nhap so nguyen a: "; cin>> a;
    cout << "Nhap so bit n: ";  cin >> n;
    long long ketquadichtrai = a << n;
    long long ketquanhan = a * pow(2, n);
    cout << "CHUNG MINH 1: a << n = a * 2^n " << endl;
    cout << "a << " << n << " = " << ketquadichtrai << endl;
    cout << "a * 2^" << n << " = " << ketquanhan << endl;

    if (ketquadichtrai == ketquanhan) 
        cout << "-> KET LUAN: Dung!" << endl;
    else 
        cout << "-> KET LUAN: Sai!" << endl;

    
    long long ketQuaDichPhai = a >> n;           
    long long ketQuaChia     = a / pow(2, n);    
    
    cout << "CHUNG MINH 2: a >> n = a / 2^n " << endl;
    cout << "a >> " << n << " = " << ketQuaDichPhai << endl;
    cout << "a / 2^" << n << " = " << ketQuaChia << endl;

    if (ketQuaDichPhai == ketQuaChia) 
        cout << "-> KET LUAN: Dung!" << endl;
    else 
        cout << "-> KET LUAN: Sai!" << endl;

}