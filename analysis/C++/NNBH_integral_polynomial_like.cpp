#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f_b(const vector<double>& a, const vector<double>& alpha, int n, double x) {
    double res = 0;
    for (int i = 0; i <= n; ++i)
        res += a[i] * pow(x, alpha[i]);
    return res;
}

double integral_b(const vector<double>& a, const vector<double>& alpha, int n, double x) {
    double res = 0;
    for (int i = 0; i <= n; ++i) {
        if (fabs(alpha[i] + 1) < 1e-12) {
            if (x == 0) {
                cout << "Loi: khong tinh duoc log(0)\n";
                return NAN;
            }
            res += a[i] * log(fabs(x));
        } else {
            res += a[i] / (alpha[i] + 1) * pow(x, alpha[i] + 1);
        }
    }
    return res;
}

void print_integral_b(const vector<double>& a, const vector<double>& alpha, int n) {
    cout << "Nguyen ham cua f(x) = ";
    for (int i = 0; i <= n; ++i) {
        if (fabs(alpha[i] + 1) < 1e-12) {
            if (i > 0 && a[i] >= 0) cout << " + ";
            cout << a[i] << "*ln|x|";
        } else {
            double coef = a[i] / (alpha[i] + 1);
            if (i > 0 && coef >= 0) cout << " + ";
            cout << coef << "*x^" << (alpha[i] + 1);
        }
    }
    cout << " + C\n";
}

int main() {
    int n;
    cout << "Nhap so luong so han n: ";
    cin >> n;
    
    double a_int, b_int;
    cout << "Nhap doan tinh tich phan [a, b]: ";
    cin >> a_int >> b_int;

    vector<double> a(n), alpha(n);
    cout << "Nhap cac a_i va alpha_i:\n";
    for (int i = 0; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n; ++i)
        cin >> alpha[i];    

    print_integral_b(a, alpha, n);

    double result = integral_b(a, alpha, n, b_int) - integral_b(a, alpha, n, a_int);
    cout << "Gia tri tich phan chinh xac: " << result << "\n";

    return 0;
}