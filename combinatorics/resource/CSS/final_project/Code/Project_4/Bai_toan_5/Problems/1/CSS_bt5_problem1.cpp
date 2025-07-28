#include <iostream>
using namespace std;

int size_of_Kn(int n) {
    // n: so dinh cua do thi Kn
    // Tra ve so canh = n * (n-1) / 2
    return n * (n - 1) / 2;
}

int size_of_Kpq(int p, int q) {
    // p, q: so dinh trong hai tap cua Kp,q
    // Tra ve so canh = p * q
    return p * q;
}

int main() {
    cout << "Size of K_5: " << size_of_Kn(5) << endl;       // 10
    cout << "Size of K_3,4: " << size_of_Kpq(3, 4) << endl; // 12
    return 0;
}