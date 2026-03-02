#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    // Dung long long so bi tran so
    long long tong = 0; 
    
    cout << "Nhap n: "; 
    cin >> n;
    cout << "Nhap so mu m: "; 
    cin >> m;
    
    // Tinh tong
    for (int i = 1; i <= n; i++) {
        tong = tong + pow(i, m);
    }
    
    cout << "Ket qua la: " << tong;
    
    return 0;
}