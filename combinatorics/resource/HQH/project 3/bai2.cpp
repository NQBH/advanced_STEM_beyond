#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
using namespace std;

// =================== B�I TO�N 2 ===================
// �?m s? ph�n ho?ch v?i ph?n t? l?n nh?t l� k

class PartitionMaxPart {
private:
    static vector<vector<int>> memo_pmax;
    
public:
    // T�nh p_max(n,k) - s? ph�n ho?ch c?a n v?i ph?n t? l?n nh?t l� k
    static int pmax(int n, int k) {
        if (k > n || k <= 0) return 0;
        if (n == 0) return (k == 0) ? 1 : 0;
        if (k == 1) return 1;
        
        // M? r?ng b?ng memo n?u c?n
        if (memo_pmax.size() <= n) {
            memo_pmax.resize(n + 1, vector<int>(n + 1, -1));
        }
        if (memo_pmax[n].size() <= k) {
            for (auto& row : memo_pmax) {
                row.resize(k + 1, -1);
            }
        }
        
        if (memo_pmax[n][k] != -1) {
            return memo_pmax[n][k];
        }
        
        // p_max(n,k) = p(n-k, k) (ph?n t? d?u ti�n ph?i l� k)
        // trong d� p(n-k, k) l� s? ph�n ho?ch c?a (n-k) v?i c�c ph?n <= k
        memo_pmax[n][k] = countPartitionsWithMaxPart(n - k, k);
        return memo_pmax[n][k];
    }
    
    // �?m s? ph�n ho?ch c?a n v?i c�c ph?n <= maxPart
    static int countPartitionsWithMaxPart(int n, int maxPart) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(maxPart + 1, 0));
        
        // dp[i][j] = s? ph�n ho?ch c?a i v?i c�c ph?n <= j
        for (int j = 0; j <= maxPart; j++) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= maxPart; j++) {
                dp[i][j] = dp[i][j-1];  // Kh�ng d�ng j
                if (i >= j) {
                    dp[i][j] += dp[i-j][j];  // D�ng j
                }
            }
        }
        
        return dp[n][maxPart];
    }
    
    // So s�nh p_k(n) v� p_max(n,k)
    static void comparePkAndPmax(int n) {
        cout << "=== Comparison p_k(n) vs p_max(n,k) for n = " << n << " ===" << endl;
        cout << "k\tp_k(" << n << ")\tp_max(" << n << ",k)" << endl;
        cout << "----------------------------------------" << endl;
        
        for (int k = 1; k <= n; k++) {
            int pk = countPartitionsWithKParts(n, k);
            int pmax_k = pmax(n, k);
            cout << k << "\t" << pk << "\t\t" << pmax_k << endl;
        }
        cout << endl;
    }
    
    static int countPartitionsWithKParts(int n, int k) {
        if (k > n || k <= 0) return 0;
        if (k == 1) return 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
        
        return dp[n][k];
    }
    
    // In ra t?t c? ph�n ho?ch v?i ph?n t? l?n nh?t l� k
    static void printAllPartitionsWithMaxPart(int n, int k) {
        cout << "All partitions of " << n << " with largest part = " << k << ":" << endl;
        vector<int> current;
        current.push_back(k);  // Ph?n t? d?u ti�n ph?i l� k
        generatePartitionsMaxPart(n - k, k, current);
        cout << endl;
    }
    
private:
    static void generatePartitionsMaxPart(int remaining, int maxVal, vector<int>& current) {
        if (remaining == 0) {
            for (int i = 0; i < current.size(); i++) {
                cout << current[i];
                if (i < current.size() - 1) cout << " + ";
            }
            cout << endl;
            return;
        }
        
        for (int i = min(remaining, maxVal); i >= 1; i--) {
            current.push_back(i);
            generatePartitionsMaxPart(remaining - i, i, current);
            current.pop_back();
        }
    }
};

vector<vector<int>> PartitionMaxPart::memo_pmax;

// =================== MAIN FUNCTION CHO B�I 2 ===================

int main() {
    cout << "=== B�I TO�N 2: PH�N HO?CH V?I PH?N T? L?N NH?T ===" << endl << endl;
    
    // Test b�i to�n 2
    int n2 = 6, k2 = 3;
    cout << "Example: n = " << n2 << ", k = " << k2 << endl;
    cout << "p_max(" << n2 << ", " << k2 << ") = " << PartitionMaxPart::pmax(n2, k2) << endl;
    cout << "p_" << k2 << "(" << n2 << ") = " << PartitionMaxPart::countPartitionsWithKParts(n2, k2) << endl << endl;
    
    PartitionMaxPart::printAllPartitionsWithMaxPart(n2, k2);
    
    // So s�nh p_k(n) v� p_max(n,k)
    for (int n = 4; n <= 7; n++) {
        PartitionMaxPart::comparePkAndPmax(n);
    }
    
    return 0;
}
