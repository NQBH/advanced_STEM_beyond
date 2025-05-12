#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double e;
    cin >> e;
    if (e <= 0) {
        cout << "epsilon phai lon hon 0." << endl;
        return 1;
    }
    int n = 0;
    const int MAX_ITERATIONS = 1000;
    
    while ((n + 1.0) / pow(3, n) >= e) {
        n++;
        if (n > MAX_ITERATIONS) {
            cout << "Khong tim thay trong " << MAX_ITERATIONS << " buoc." << endl;
            return 1;
        }
    }
    cout << n << endl;
    
    return 0;
}
