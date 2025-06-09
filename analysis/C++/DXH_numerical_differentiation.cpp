#include<iostream>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;

class DerivativeApproximator {
private:
    double m_x; // Tên thuộc tính nên có tiền tố để dễ phân biệt, ví dụ m_ (member)
    double m_h;
    // Hàm và đạo hàm của hàm đó
    std::function<double(double)> m_func;
    std::function<double(double)> m_func_prime;

public:
    // Constructor nhận các hàm và giá trị x, h
    DerivativeApproximator(std::function<double(double)> func,
                           std::function<double(double)> func_prime,
                           double x_val, double h_val)
        : m_func(func), m_func_prime(func_prime), m_x(x_val), m_h(h_val) {}
    //Phương thức tính hàm
    double caculateNewtonForward() {
        return (m_func(m_x + m_h) - m_func(m_x)) / m_h;
    }
    double caculateNewtonBackward() {
        return (m_func(m_x) - m_func(m_x - m_h)) / m_h;
    }
    double caculateStirling(double x, double h, std::function<double(double)> func) {
        return (func(x + h) - func(x - h)) / (2 * h);
    }
};
int main() {
    // Định nghĩa hàm và đạo hàm của nó
    auto func = [](double x) { return x * x; }; // Hàm f(x) = x^2
    auto func_prime = [](double x) { return 2 * x; }; // Đạo hàm f'(x) = 2x

    double x_val = 1.0; // Giá trị x tại đó ta muốn tính đạo hàm
    double h_val = 0.01; // H

    DerivativeApproximator approximator(func, func_prime, x_val, h_val);

    cout << fixed << setprecision(4);
    cout  << approximator.caculateNewtonForward() << endl;
    cout  << approximator.caculateNewtonBackward() << endl;
    cout  << approximator.caculateStirling(x_val, h_val, func) << endl;

    return 0;
}