#include <iostream>

using namespace std;

double a, b, c;

double f(double a_val, double b_val, double c_val, double x) {
    return a_val * x * x + b_val * x + c_val;
}

double F(int n, double alpha) {
    double current_a = alpha; 
    for (int i = 0; i < n; i++) {
        current_a = f(a, b, c, current_a); 
    }
    
    return current_a;
}

int main() {
    int n;
    double alpha;

    cout << "--- Chuong trinh tinh day so truy hoi a_n ---" << endl;
    
    cout << "Nhap cac he so a, b, c cho ham f(x) = ax^2 + bx + c: ";
    cin >> a >> b >> c;

    cout << "Nhap gia tri alpha (gia tri khoi tao a_0): ";
    cin >> alpha;

    cout << "Nhap vi tri n cua so hang can tinh: ";
    cin >> n;

    double result = F(n, alpha);
    cout << "=> Gia tri cua a_" << n << " la: " << result << endl;

    return 0;
}
