#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;
    cout << " nhap so " << endl;
    cin >> a >> b >> c >> d;
    
    // tinh delta A
    double det = (a * d) - (b * c);
    cout << " dinh thuc del A = " << det << endl;
    return 0;

}