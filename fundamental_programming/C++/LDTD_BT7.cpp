#include <iostream>
using namespace std;

int main() {
    double a = 3;
    double b = 5;
    double c = 7;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    cout << "c= ";
    cin >> c;
    double max = a;
    double min = a;
    //tìm max, min
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    cout << "Gia tri lon nhat (Max) la: " << max << endl;
    cout << "Gia tri nho nhat (Min) la: " << min << endl;
    return 0;
}