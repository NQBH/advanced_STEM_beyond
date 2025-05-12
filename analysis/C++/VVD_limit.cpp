#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon;
    cout << "NHap gia tri epsilon (ε > 0): ";
    cin >> epsilon;

    if (epsilon <= 0) {
        cout << "ε phai lon hon 0." << endl;
        return 1;
    }

    int N_opt = ceil(log2(1 / epsilon));
    cout << "Gia tri N toi uu là: " << N_opt << endl;

    return 0;
}