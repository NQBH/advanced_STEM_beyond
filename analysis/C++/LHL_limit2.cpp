#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double M;
    cout << "Nhap gia tri M (M>0): ";
    cin >> M;

    if (M <= 0) {
        cout << "M > 0." << endl;
        return 1;
    }

    int n = 0;
    while (sqrt(n + 2) <= M) {
        n++;
    }

    cout << "GTNN cua N thoa man sqrt(n + 2) > M la: " << n << endl;
    return 0;
}