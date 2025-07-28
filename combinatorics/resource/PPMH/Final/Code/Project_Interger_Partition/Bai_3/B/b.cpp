#include <iostream>
#include <vector>

using namespace std;

// Hàm kiểm tra phân hoạch có phải tự liên hợp không
bool isSelfConjugate(const vector<int>& part) {
    int n = part.size();
    for (int i = 0; i < n; ++i) {
        if (part[i] < i + 1) return false;
    }
    return true;
}

// Sinh tất cả phân hoạch của n
void generatePartitions(int n, int max_val, vector<int>& curr,
                        vector<vector<int>>& oddPartitions,
                        vector<vector<int>>& selfConjugates) {
    if (n == 0) {
        if (curr.size() % 2 == 1) {
            oddPartitions.push_back(curr);
        }
        if (isSelfConjugate(curr)) {
            selfConjugates.push_back(curr);
        }
        return;
    }
    for (int i = min(n, max_val); i >= 1; --i) {
        curr.push_back(i);
        generatePartitions(n - i, i, curr, oddPartitions, selfConjugates);
        curr.pop_back();
    }
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;

    vector<int> current;
    vector<vector<int>> oddPartitions;
    vector<vector<int>> selfConjugates;

    generatePartitions(n, n, current, oddPartitions, selfConjugates);

    cout << "\nPhân hoạch có số phần tử lẻ:\n";
    for (const auto& p : oddPartitions) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }

    cout << "\nPhân hoạch tự liên hợp:\n";
    for (const auto& p : selfConjugates) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }

    cout << "\nTổng số phân hoạch có phần tử lẻ: " << oddPartitions.size() << endl;
    cout << "Tổng số phân hoạch tự liên hợp: " << selfConjugates.size() << endl;

    if (oddPartitions.size() == selfConjugates.size()) {
        cout << "Bng nhau.\n";
    } else {
        cout << "Không bằng nhau.\n";
    }

    return 0;
}