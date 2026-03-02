#include <iostream>
using namespace std;

int main() {
    float a, b, c;
    cout << "Nhap so thuc a: ";
    cin >> a;
    cout << "Nhap so thuc b: ";
    cin >> b;
    cout << "Nhap so thuc c: ";
    cin >> c;

   
    float maxVal = a; 
    if (b > maxVal) {
        maxVal = b; 
    }
    if (c > maxVal) {
        maxVal = c; 
    }

    
    float minVal = a; 
    if (b < minVal) {
        minVal = b;
    }
    if (c < minVal) {
        minVal = c;
    }

    cout << "So lon nhat la: " << maxVal << endl;
    cout << "So nho nhat la: " << minVal << endl;

    return 0;
}
