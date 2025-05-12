//Câu b
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double epsilon;
    cout << "Nhap epsilon (ε > 0): ";
    cin >> epsilon;

    if (epsilon <= 0) {
        cout << "ε phai lon hon 0.\n";
        return 1;
    }

    int N_eps = ceil(1.0 / epsilon - 1);
    cout << "Gia tri N_epsilon toi uu la: " << N_eps << endl;

    return 0;
}