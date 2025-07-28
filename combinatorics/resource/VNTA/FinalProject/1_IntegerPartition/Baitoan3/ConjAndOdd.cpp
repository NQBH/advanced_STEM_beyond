#include <bits/stdc++.h>
using namespace std;

bool isSelfConjugate(const vector<int>& parts) {
    int m = (int)parts.size();
    vector<int> conjugate(m, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m && parts[j] >= i + 1; ++j) {
            ++conjugate[i];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (parts[i] != conjugate[i]) return false;
    }
    return true;
}

void genSelfConjugatePartitions(int n, int k, int maxVal, vector<int>& curr, vector<vector<int>>& result) {
    if (k == 0 && n == 0) {
        if (isSelfConjugate(curr)) {
            result.push_back(curr);
        }
        return;
    }
    if (k <= 0 || n <= 0) return;

    for (int i = min(maxVal, n); i >= 1; --i) {
        curr.push_back(i);
        genSelfConjugatePartitions(n - i, k - 1, i, curr, result);
        curr.pop_back();
    }
}

void genAllSelfConjugatePartitions(int n, int maxVal, vector<int>& curr, vector<vector<int>>& result) {
    if (n == 0) {
        if (isSelfConjugate(curr)) {
            result.push_back(curr);
        }
        return;
    }
    for (int i = min(maxVal, n); i >= 1; --i) {
        curr.push_back(i);
        genAllSelfConjugatePartitions(n - i, i, curr, result);
        curr.pop_back();
    }
}

int countOddParts(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int odd = 1; odd <= n; odd += 2) {
        for (int i = odd; i <= n; ++i) {
            dp[i] += dp[i - odd];
        }
    }
    return dp[n];
}

void genOddPartitions(int n, int minOdd, vector<int>& curr, vector<vector<int>>& result) {
    if (n == 0) {
        result.push_back(curr);
        return;
    }
    if (n < 0) return;

    for (int odd = minOdd; odd <= n; odd += 2) {
        curr.push_back(odd);
        genOddPartitions(n - odd, odd, curr, result);
        curr.pop_back();
    }
}

void genDistinctOddPartitions(int n, int start, vector<int>& curr, vector<vector<int>>& result) {
    if (n == 0) {
        result.push_back(curr);
        return;
    }
    if (n < 0) return;

    for (int odd = start; odd <= n; odd += 2) {
        curr.push_back(odd);
        genDistinctOddPartitions(n - odd, odd + 2, curr, result);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Tổng số phân hoạch tự liên hợp của n
    vector<vector<int>> allSelfConjParts;
    vector<int> curr;
    for (int partsCount = 1; partsCount <= n; ++partsCount) {
        genSelfConjugatePartitions(n, partsCount, n, curr, allSelfConjParts);
    }

    cout << "\n=== Tong so phan hoach tu lien hop cua " << n << ": " << allSelfConjParts.size() << "\n";
    for (const auto& part : allSelfConjParts) {
        for (int i = 0; i < (int)part.size(); ++i) {
            cout << part[i];
            if (i < (int)part.size() - 1) cout << " + ";
        }
        cout << "\n";
    }

    // Phân hoạch thành odd parts
    int oddPartsCount = countOddParts(n);
    cout << "\n=== So phan hoach cua " << n << " co phan le: " << oddPartsCount << "\n";
    vector<vector<int>> oddParts;
    curr.clear();
    genOddPartitions(n, 1, curr, oddParts);

    for (auto& part : oddParts) {
        sort(part.rbegin(), part.rend());
    }
    sort(oddParts.begin(), oddParts.end());

    for (const auto& part : oddParts) {
        for (int i = 0; i < (int)part.size(); ++i) {
            cout << part[i];
            if (i < (int)part.size() - 1) cout << " + ";
        }
        cout << "\n";
    }

    // Phân hoạch thành distinct odd parts
    vector<vector<int>> distinctOddParts;
    curr.clear();
    genDistinctOddPartitions(n, 1, curr, distinctOddParts);

    cout << "\n=== So phan hoach cua " << n << " thanh cac phan le phan biet: " << distinctOddParts.size() << "\n";

    for (auto& part : distinctOddParts) {
        sort(part.rbegin(), part.rend());
    }
    sort(distinctOddParts.begin(), distinctOddParts.end());

    for (const auto& part : distinctOddParts) {
        for (int i = 0; i < (int)part.size(); ++i) {
            cout << part[i];
            if (i < (int)part.size() - 1) cout << " + ";
        }
        cout << "\n";
    }

    // So sánh
    cout << "\n=== So sanh:\n";
    cout << "Tong so phan hoach tu lien hop = " << allSelfConjParts.size() << "\n";
    cout << "So phan hoach distinct odd parts = " << distinctOddParts.size() << "\n";
    if (allSelfConjParts.size() == distinctOddParts.size()) {
        cout << "=> Bang nhau";
    } else {
        cout << "=> Khac nhau\n";
    }

    return 0;
}
