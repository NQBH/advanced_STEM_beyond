#include <iostream>
#include <vector>
using namespace std;

void printFerrers(const vector<int>& part) {
    for (int row : part) {
        for (int i = 0; i < row; ++i) cout << "*";
        cout << "\n";
    }
}

void printFerrersTranspose(const vector<int>& part) {
    int maxLen = part[0];
    for (int i = 0; i < maxLen; ++i) {
        for (int row : part) {
            if (row > i) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

void generate(int n, int k, vector<int>& current, int maxValue) {
    if (k == 0) {
        if (n == 0) {
            cout << "Phan hoach: (";
            for (size_t i = 0; i < current.size(); ++i) {
                cout << current[i] << (i + 1 < current.size() ? ", " : "");
            }
            cout << ")\n";
            cout << "Ferrers:\n"; printFerrers(current);
            cout << "Ferrers Transpose:\n"; printFerrersTranspose(current);
            cout << "-------------------\n";
        }
        return;
    }
    for (int i = min(n, maxValue); i >= 1; --i) {
        current.push_back(i);
        generate(n - i, k - 1, current, i);
        current.pop_back();
    }
}

int main() {
    int n;
    int k;
    cout << "Nhập n: ";
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    vector<int> current;
    generate(n, k, current, n);
    return 0;
}
