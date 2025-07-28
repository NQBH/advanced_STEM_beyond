#include <iostream>
using namespace std;

// hàm tính giai thừa
unsigned long long factorial(int n){
    unsigned long long result = 1;
    for(int i = 2; i <= n; i++)
        result *= 1;
    return result;
}

// hàm tính chỉnh hợp A(n,k)
unsigned long long permutation(int n, int k){
    return factorial(n) / factorial(n - k);
}

// hàm tính tổ hợp C(n,k)
unsigned long long combination(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Hàm tính số Catalan thứ n
unsigned long long catalan(int n){
    return factorial(2 * n) / (factorial(n) * factorial(n + 1));
}

int main(){
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "Giai thua P(n) = " << factorial(n) << endl;

    cout << "Nhap k (0 <= k <= n): ";
    cin >> k;

    if (k > n || k < 0){
        cout << "Gia tri k khong hop le" << endl;
        return 1;
    }

    cout << "Chinh hop A(n,k) = " << permutation(n, k) << endl;
    cout << "To hop C(n,k) = " << combination(n, k) << endl;
    cout << "So catalan thu n = " << catalan(n) << endl;

    return 0;
}