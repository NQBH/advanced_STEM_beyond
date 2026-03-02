#include <iostream>
using namespace std;

int main() {
    int n;
    int am = 0, duong = 0, ko = 0;
    double num;

    cout << "nhap n so thuc: ";
    cin >> n;

    //dem
    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> num;

        if (num < 0) {
            am += 1;
        } else if (num > 0) {
            duong += 1;
        } else {
            ko += 1;
        }
    }  
    
    cout << "so duong: " << duong << endl;
    cout << "so am: " << am << endl;
    cout << "so 0: " << ko << endl;
    
}