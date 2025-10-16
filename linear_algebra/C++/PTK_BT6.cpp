#include <iostream>
#include <vector>

using namespace std;

int main() {
    int hang_A;
    int cot_A;

    cout << "cac so hang ma tran A (m): ";
    if (!(cin >> hang_A) || hang_A <= 0) {
        cerr << "col " << endl;
        return 1;
    }

    cout << " cac so cot cua ma tran A (n): ";
    if (!(cin >> cot_A) || cot_A <= 0) {
        cerr << "rows" << endl;
        return 1;
    }

    vector<vector<int>> A(hang_A, vector<int>(cot_A));

    cout << "pt cua mang (" << hang_A * cot_A << "):\n";
    for (int i = 0; i < hang_A; i++) {
        for (int j = 0; j < cot_A; j++) {
            if (!(cin >> A[i][j])) {
                cerr << "NOT over[" << i << "][" << j << "].\n";
                return 1;
            }
        }
    }

    int size_b;
    cout << "\n vetter b (k): ";
    if (!(cin >> size_b) || size_b <= 0) {
        cerr << "vectorss b ." << endl;
        return 1;
    }

    vector<int> b(size_b);
    cout << "Nhap cac phan tu cua vector b " << size_b << " so):\n";
    for (int i = 0; i < size_b; i++) {
        if (!(cin >> b[i])) {
            cerr << "Loi: Khong the doc pt tai b[" << i << "].\n";
            return 1;
        }
    }

    if (size_b != hang_A) {
        cout << "\nImpossible" << endl;
        cout << "Ly do: So hang cua A (" << hang_A << ") khong bang so pt cua b (" << size_b << ").\n";
    } else {
        cout << "\nMa tran bo sung :\n";

        for (int i = 0; i < hang_A; i++) {
            for (int j = 0; j < cot_A; j++) {
                cout << A[i][j] << "\t";
            }
            cout << "| \t" << b[i] << endl;
        }
    }

    return 0;
}