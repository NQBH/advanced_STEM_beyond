#include <iostream>
#include <limits>

using namespace std;

typedef unsigned long long ull;

// hàm tính giai thừa(check overflow)
bool factorial(int n, ull &result){
    result = 1;
    for(int i = 2; i <= n; ++i){
        if(result > ULLONG_MAX / i) return false; //overflow
        result *= 1;
    }
    return true;
}

// chỉnh hợp A(n,k)
bool permutation(int n, int k, ull &result){
    ull fn, fnk;
    if(!factorial(n, fn) || !factorial(n-k,fnk)) return false;
    result = fn / fnk;
    return true;
}

// tổ hợp C(n,k)
bool combination(int n, int k, ull &result){
    ull fn, fk, fnk;
    if(!factorial(n, fn) || !factorial(k, fk) || !factorial(n-k,fnk)) return false;
    result = fn / (fk * fnk);
    return true;
}

// số catalan
bool catalan(int n, ull &result){
    ull f2n, fn, fn1;
    if(!factorial(2 * n, f2n) || !factorial(n,fn) || !factorial(n+1, fn1)) return false;
    result = f2n / (fn * fn1);
    return true;
}

// Tìm giá trị nhỏ nhất của n gây overflow cho biểu thức
void find_overflow_point() {
    int n = 1;
    ull res;

    // (a) Pn = n!
    while (factorial(n, res)) ++n;
    cout << "Overflow o P(n) khi n = " << n << endl;

    // (b) Ak_n
    n = 1;
    while (permutation(n, n / 2, res)) ++n;
    cout << "Overflow o A(n,k) khi n = " << n << ", k = " << n/2 << endl;

    // (c) Ck_n
    n = 1;
    while (combination(n, n / 2, res)) ++n;
    cout << "Overflow o C(n,k) khi n = " << n << ", k = " << n/2 << endl;

    // (d) Catalan
    n = 1;
    while (catalan(n, res)) ++n;
    cout << "Overflow o Catalan khi n = " << n << endl;
}

int main() {
    int n, k;
    ull result;

    cout << "Nhap n: ";
    cin >> n;

    if (factorial(n, result))
        cout << "Pn = " << result << endl;
    else
        cout << "Pn bi overflow!\n";

    cout << "Nhap k (0 <= k <= n): ";
    cin >> k;

    if (permutation(n, k, result))
        cout << "Ak_n = " << result << endl;
    else
        cout << "Ak_n bi overflow!\n";

    if (combination(n, k, result))
        cout << "Ck_n = " << result << endl;
    else
        cout << "Ck_n bi overflow!\n";

    if (catalan(n, result))
        cout << "Catalan(n) = " << result << endl;
    else
        cout << "Catalan(n) bi overflow!\n";

    cout << "\n-- Tim gia tri n nho nhat gay overflow --\n";
    find_overflow_point();

    return 0;
}
