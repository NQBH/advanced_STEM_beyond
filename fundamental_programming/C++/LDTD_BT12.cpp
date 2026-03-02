#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    
    int n, m;
    double tong = 0; 
    
    cout << "Nhap vao so n (gioi han day so): ";
    cin >> n;
    cout << "Nhap vao so mu m: ";
    cin >> m;

    for (int i = 1; i <= n; i++) {
        tong = tong + pow(i, m); 
    }

    cout << "Ket qua tong Sm la: " << tong << endl;

    return 0;
}