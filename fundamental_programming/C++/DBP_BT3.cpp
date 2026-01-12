#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0){
        cout << -1;
    }
    else if (a == b && b == c){
        cout < "HLP";
    }
    else{
        cout <<"dien tich xung quanh" << 2 * (a + b) * c << endl;
        cout <<"dien tich toan phan" << 2 * (a * b + a * c + b * c) << endl;
        cout <<"duong cheo" << sqrt(a * a + b * b) << endl;
        cout <<"the tich" << a * b * c << endl;
    }
    return 0;
}