#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;
    
    if (pow(2, n) >= 100)
        cout << "True" << endl;
    else 
        cout << "S" << endl; 
        
        return 0;
}