#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon;
    cout << "Nhap epsilon (epsilon > 0): ";
    cin >> epsilon;

    // Kiểm tra điều kiện đầu vào
    if (epsilon <= 0) {
        cout << "Loi: epsilon phai lon hon 0." << endl;
        return 1;
    }

    int n = 0;
    const int MAX_ITER = 1000;


    while ((n + 1) / pow(3, n) >= epsilon) {
        n++;
        if (n > MAX_ITER) {
            cout << "Khong tim thay n thoa dieu kien trong " << MAX_ITER << " buoc." << endl;
            return 1;
        }
    }

    cout << "Gia tri n_epsilon la: " << n << endl;

    return 0;
}