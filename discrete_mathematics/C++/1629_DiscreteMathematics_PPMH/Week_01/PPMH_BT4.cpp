#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n;
    cout << "Nhap so thuc:";
    cin >> n;
    
    double value = pow(2,n);
    
    cout << "Gia tri 2^" << n << " = " << value << endl;
    if(value >= 100){
        cout << "Dung" << endl;
    } else {
        cout << "Sai" << endl;
    }
    return 0;
}