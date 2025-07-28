#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void enumerate_perfect_matchings(int p, int q) {
    if (p != q) {
        cout << "Không tồn tại ghép cặp hoàn hảo vì p ≠ q.\n";
        return;
    }

    vector<string> U, V;
    for (int i = 1; i <= p; ++i) {
        U.push_back("u" + to_string(i));
        V.push_back("v" + to_string(i));
    }

    sort(V.begin(), V.end()); 

    int count = 0;
    do {
        cout << "Matching " << ++count << ": ";
        for (int i = 0; i < p; ++i) {
            cout << "(" << U[i] << "," << V[i] << ") ";
        }
        cout << endl;
    } while (next_permutation(V.begin(), V.end()));

    cout << "\nTổng số perfect matching: " << count << endl;
}

int main() {
    int p, q;
    cout << "Nhập số đỉnh bên trái (p): ";
    cin >> p;
    cout << "Nhập số đỉnh bên phải (q): ";
    cin >> q;

    enumerate_perfect_matchings(p, q);
    return 0;
}