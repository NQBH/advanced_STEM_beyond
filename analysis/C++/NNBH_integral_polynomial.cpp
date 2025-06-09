#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f_a(const vector<double>& a, int n, double x) {
    double res = 0;
    for (int i = n; i >= 0; --i)
        res += a[i] * pow(x, i);
    return res;
}

double integral_a(const vector<double>& a, int n, double x) {
    double res = 0;
    for (int i = n; i >= 0; --i)
        res += a[i] / (i + 1) * pow(x, i + 1);
    return res;
}

void print_integral_a(const vector<double>& a, int n) {
    cout << "Nguyen ham cua P(x) = ";
    for (int i = n; i >= 0; --i) {
        double coef = a[i] / (i + 1);
        if (i > 0 && coef >= 0)
            cout << coef << "*x^" << (i + 1) << " + ";
    }
    cout << "C\n";
}

int main() {
    int n;
    cout << "Nhap bac da thuc n: ";
    cin >> n;

    double a_int, b_int;
    cout << "Nhap doan tinh tich phan [a, b]: ";
    cin >> a_int >> b_int;

    vector<double> a(n + 1);
    cout << "Nhap he so a_i:\n";
    for (int i = n; i >= 0; --i) cin >> a[i];

    print_integral_a(a, n);

    double result = integral_a(a, n, b_int) - integral_a(a, n, a_int);
    cout << "Gia tri tich phan chinh xac: " << result << "\n";

    return 0;
}