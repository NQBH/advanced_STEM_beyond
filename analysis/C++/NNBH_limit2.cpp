#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon;
    cout << "Nhap so epsilon: ";
    cin >> epsilon;

    int n = 2; 
    double a_prev = sqrt(n + 1); 
    double a_curr = sqrt(n + 2); 
    double diff = fabs(a_curr - a_prev);

    while (diff >= epsilon) {
        n++;
        a_prev = a_curr;
        a_curr = sqrt(n + 2);
        diff = fabs(a_curr - a_prev);
    }

    cout << "Gia tri n nho nhat sao cho |a_n - a_(n-1)| < epsilon la: " << n << endl;
    cout << "Gia tri a_n: " << a_curr << ", a_(n-1): " << a_prev << ", hieu: " << diff << endl;

    return 0;
}