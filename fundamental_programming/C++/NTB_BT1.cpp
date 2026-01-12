#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float CV, S, C;
    cout << "nhap canh c:";
    cin >> C;
    CV = C * 4;
    S = C * C;
    cout << " vay chu vi hinh vuong la: " << CV << endl;
    cout << "vay dien tich hinh vuong la: " << S << endl;
    return 0;
}