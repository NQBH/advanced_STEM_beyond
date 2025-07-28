#include <iostream>
#include <vector>

using namespace std;

// Kiểm tra xem phân hoạch có phải tự liên hợp không
bool isSelfConjugate(const vector<int>& part) {
    int n = part.size();
    for (int i = 0; i < n; ++i) {
        if (part[i] < i + 1) return false;
    }
    return true;
}

void generatePartitions(int n, int max, vector<int>& curr, int k, int& count) {
    if (n == 0 && curr.size() == k && isSelfConjugate(curr)) {
        ++count;
        for (int v : curr) cout << v << " ";
        cout << endl;
        return;
    }
    for (int i = min(n, max); i >= 1; --i) {
        curr.push_back(i);
        generatePartitions(n - i, i, curr, k, count);
        curr.pop_back();
    }
}

int main() {
    int n;
    int k;
    cout << "Nhập n: ";
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    vector<int> curr;
    int count = 0;
    generatePartitions(n, n, curr, k, count);
    cout << "Tổng số phân hoạch tự liên hợp có " << k << " phần: " << count << endl;
    return 0;
}
