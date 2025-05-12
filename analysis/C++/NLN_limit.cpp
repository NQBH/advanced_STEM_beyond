#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    cout << "Nhập giá trị E (E > 0): ";
    double E;
    cin >> E;

    if (E <= 0) {
        cerr << "Giá trị E phải lớn hơn 0!\n"; 
        return 1; 
    }

    int N = 0;
    double current_power_of_2 = 1.0; 
    while (current_power_of_2 < 1.0 / E) {
        N++; 
        current_power_of_2 *= 2.0; 
    }

    cout << "Giá trị N (số nguyên không âm nhỏ nhất sao cho 1/2^N <= E) cho E = " << E << " là: " << N << "\n";

    return 0;
}