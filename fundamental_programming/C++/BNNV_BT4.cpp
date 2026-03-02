#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    // Problem 4
    
    //4.1
	double x, y;
	cin >> x >> y;
    
    cout << "sqrt: ";
	if (x < 0) cout << "x khong duoc am";
	else cout << sqrt(x) << endl;
    

    //4.2
    cout << "pow: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << pow(x, y) << endl;
    

    //4.3
    cout << "exp: ";
    cout << exp(x) << endl;
    

    //4.4
    cout << "log: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << log(x) << endl;
    

    //4.5
    cout << "log10: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << log10(x) << endl;
    

    //4.6 
    cout << "abs: ";
    cout << abs(x) << endl;
    cout << "labs: ";
    cout << labs(x) << endl;
    cout << "fabs: ";
    cout << fabs(x) << endl;
    

    //4.7
    double rad = x * M_PI / 180;
    cout << "cos: ";
    cout << cos(rad) << endl;
    cout << "sin: ";
    cout << sin(rad) << endl;
    cout << "tan: ";
    cout << tan(rad) << endl;
    

    //4.8
    cout << "acos: ";
    if ( rad < -1 || rad > 1) {
        cout << "lan nay thi anh chiu thua" << endl;
    } else cout << acos(x) << endl;

    cout << "asin: ";
    if ( rad < -1 || rad > 1) {
        cout << "lan nay thi anh chiu thua" << endl;
    } else cout << asin(x) << endl;
    
    cout << "atan: ";
    cout << atan(x) << endl;

    
    //4.9
    cout << "floor: ";
    cout << floor(x) << endl;

    cout << "ceil: ";
    cout << ceil(x) << endl;
    
}