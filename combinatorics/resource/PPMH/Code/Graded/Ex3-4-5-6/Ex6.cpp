#include <iostream>
#include <cmath>

using namespace std;

// Tính f(n) bằng quy hoạch động
unsigned long long f(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;

    unsigned long long prev2 = 1, prev1 = 2, curr;
    for (int i = 2; i <= n; ++i){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// Tính f(n) bằng công thức Binet
double closed_form_f(int n){
    double sqrt5 = sqrt(5);
    double tau = (1 + sqrt5) / 2;
    double tau_bar = (1 - sqrt5) / 2;
    return (pow(tau, n+2) + pow(tau_bar, n)) / sqrt5;
}

int main(){
    for(int i = 1; i <= 10; ++i){
        cout << "f(" << i << ") = " << f(i) << ", xap xi = " << round(closed_form_f(i)) << endl;
    return 0;
    }
}