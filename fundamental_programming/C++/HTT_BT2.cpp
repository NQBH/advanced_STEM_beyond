#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b; 

    cout << "Chieu dai cua a la: " ;
    cout << "\n";
    cin >> a;
    cout << "Chieu rong cua b la: ";
    cout << "\n";
    cin >> b;

    int C = 2 * ( a + b);       
    int S = a * b;             
    int d = sqrt(a * a + b * b); 

    cout << "Chu vi HCN la: " << C << '\n';
    cout << "Dien tich HCN la: " << S << '\n';
    cout << "Do dai duong cheo HCN la: " << d << '\n';

    return 0;
}