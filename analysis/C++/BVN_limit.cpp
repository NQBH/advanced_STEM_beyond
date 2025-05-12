#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double E; 
    cout << "Nhập giá trị E (E > 0): ";
    cin >> E;

    if (E <= 0) {
        cout << "Giá trị E phải lớn hơn 0!" << endl;
        return 1; 
    }

    int N = 0; 
    while (1.0 / pow(2, N) > E) { 
        N++;
    }

    cout << "Giá trị N tối ưu cho E = " << E << " là: " << N << endl;
    return 0;
}