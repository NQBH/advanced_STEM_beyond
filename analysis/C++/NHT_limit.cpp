#include <iostream>
#include <cmath>    

using namespace std;

int main() {
    double epsilon;
    cout << "Nhap epsilon (ε > 0): ";
    cin >> epsilon;

    if (epsilon <= 0) {
        cout << "ε phai lon hon 0." << endl;
        return 1;
    }

    int N_opt = ceil(log2(1.0 / epsilon));
    cout << "Gia tri N_epsilon toi uu la: " << N_opt << endl;

    return 0;
}