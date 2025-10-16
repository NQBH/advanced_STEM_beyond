//BT10
#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;  

    cout << " a: ";
    cin >> a;
    cout << " b: ";
    cin >> b;
    cout << " c: ";
    cin >> c;
    cout << " d: ";
    cin >> d;
    double det = (a * d) - (b * c);

    cout << "Dinh thuc ma tran : " << det << endl;

    return 0;
}