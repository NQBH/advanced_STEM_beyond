#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, y;
    int absX = abs(x);
    long labsX = labs(x);
    cout << "nhap x: ";
    cin >> x;
    cout << "nhap y: ";
    cin >> y;
    if (x,y > 0){
        cout << "sqrt= " << sqrt(x) << endl;
        cout << "pow= " << pow(x,y) << endl;
        cout << "exp= " << exp(x) << endl;
        cout << "log= " << log(x) << endl;
        cout << "log10= " << log10(x) << endl;
        cout << "abs= " << abs(x) << endl;
        cout << "labs= " << labs(x) << endl;
        cout << "fabs= " << fabs(x) << endl;
        cout << "cos= " << cos(x) << endl;
        cout << "sin= " << sin(x) << endl;
        cout << "tan= " << tan(x) << endl;
    if (x >= -1 && x <=1){
        cout << "acos= " << acos(x) << endl;
        cout << "asin= " << asin(x) << endl;
    }
        cout << "atan= " << atan(x) << endl;
        cout << "floor= " << floor(x) << endl;
        cout << "ceil= " << ceil(x) << endl;
    }else{
        cout << "sqrt= " << sqrt(x) << endl;
        cout << "pow= " << pow(x,y) << endl;
        cout << "exp= " << exp(x) << endl;
        cout << "log= " << log(x) << endl;
        cout << "log10= " << log10(x) << endl;
        cout << "abs= " << abs(x) << endl;
        cout << "labs= " << labs(x) << endl;
        cout << "fabs= " << fabs(x) << endl;
        cout << "cos= " << cos(x) << endl;
        cout << "sin= " << sin(x) << endl;
        cout << "tan= " << tan(x) << endl;
    if (x >= -1 && x <=1){
        cout << "acos= " << acos(x) << endl;
        cout << "asin= " << asin(x) << endl;
    }
        cout << "atan= " << atan(x) << endl;
        cout << "floor= " << floor(x) << endl;
        cout << "ceil= " << ceil(x) << endl;
    }
return 0;
}
