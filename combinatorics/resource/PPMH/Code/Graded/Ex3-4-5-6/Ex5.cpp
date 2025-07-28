#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

// hàm tính giai thừa
ull factorial(int n){
    ull result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

// tính số hoán vị không cố định (derangement) bằng công thức tổ hợp
ull derangement_formula(int n){
    ull fact = factorial(n);
    double sum = 0;
    for (int i = 0; i <= n; ++i)
        sum += (i % 2 == 0 ? 1.0 : -1.0) / factorial(i);
    return static_cast<ull>(round(fact * sum));
}

// tính gần đúng bằng n! / e
ull derangement_approx(int n){
    double e = exp(1.0);
    ull fact = factorial(n);
    return static_cast<ull>(round(fact / e));
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Derangement f(" << n << ") theo cong thuc to hop: " << derangement_formula(n) << endl;
    cout << "Derangement f(" << n << ") gan dung bang n!/e: " << derangement_approx(n) << endl;

    return 0;
}