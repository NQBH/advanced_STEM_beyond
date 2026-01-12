#include <iostream>
using namespace std;
int main () {
    int a;
    cin >> a ;
    // Tính diện tích hình vuông cạnh a
    int S = a * a;
    cout << "Tính diện tích hình vuông cạnh a = " << a << " bằng " << S << '\n';
    // Tính chu vi hình vuông canh a
    int C = a * 4;
    cout << "Tính chu vi hình vuông cạnh a = " << a << " bằng " << C << '\n';
    return 0;
}