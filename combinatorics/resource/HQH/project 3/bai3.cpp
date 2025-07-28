#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
using namespace std;

// =================== B�I TO�N 3 ===================
// Ph�n ho?ch t? li�n h?p (self-conjugate partitions)

class SelfConjugatePartition {
public:
    // Ki?m tra xem m?t ph�n ho?ch c� t? li�n h?p kh�ng
    static bool isSelfConjugate(const vector<int>& partition) {
        if (partition.empty()) return true;
        
        // T�nh ph�n ho?ch chuy?n v?
        int maxPart = partition[0];
        vector<int> conjugate(maxPart, 0);
        
        for (int part : partition) {
            for (int i = 0; i < part; i++) {
                conjugate[i]++;
            }
        }
        
        // Lo?i b? c�c ph?n t? 0
        while (!conjugate.empty() && conjugate.back() == 0) {
            conjugate.pop_back();
        }
        
        return partition == conjugate;
    }
    
    // �?m s? ph�n ho?ch t? li�n h?p c� k ph?n
    static int countSelfConjugateWithKParts(int n, int k) {
        vector<vector<int>> allPartitions;
        vector<int> current;
        generateAllPartitionsWithKParts(n, k, k, current, allPartitions);
        
        int count = 0;
        for (const auto& partition : allPartitions) {
            if (isSelfConjugate(partition)) {
                count++;
            }
        }
        return count;
    }
    
    // �?m t?ng s? ph�n ho?ch t? li�n h?p
    static int countAllSelfConjugate(int n) {
        int total = 0;
        for (int k = 1; k <= n; k++) {
            total += countSelfConjugateWithKParts(n, k);
        }
        return total;
    }
    
    // In t?t c? ph�n ho?ch t? li�n h?p c� k ph?n
    static void printSelfConjugateWithKParts(int n, int k) {
        cout << "Self-conjugate partitions of " << n << " with " << k << " parts:" << endl;
        
        vector<vector<int>> allPartitions;
        vector<int> current;
        generateAllPartitionsWithKParts(n, k, k, current, allPartitions);
        
        for (const auto& partition : allPartitions) {
            if (isSelfConjugate(partition)) {
                for (int i = 0; i < partition.size(); i++) {
                    cout << partition[i];
                    if (i < partition.size() - 1) cout << " + ";
                }
                cout << endl;
                
                // In bi?u d? Ferrers
                cout << "Ferrers diagram:" << endl;
                for (int part : partition) {
                    for (int j = 0; j < part; j++) {
                        cout << "* ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    
    // In t?t c? ph�n ho?ch t? li�n h?p
    static void printAllSelfConjugate(int n) {
        cout << "=== All self-conjugate partitions of " << n << " ===" << endl;
        
        for (int k = 1; k <= n; k++) {
            vector<vector<int>> allPartitions;
            vector<int> current;
            generateAllPartitionsWithKParts(n, k, k, current, allPartitions);
            
            bool found = false;
            for (const auto& partition : allPartitions) {
                if (isSelfConjugate(partition)) {
                    if (!found) {
                        cout << "With " << k << " parts:" << endl;
                        found = true;
                    }
                    
                    for (int i = 0; i < partition.size(); i++) {
                        cout << partition[i];
                        if (i < partition.size() - 1) cout << " + ";
                    }
                    cout << endl;
                }
            }
            if (found) cout << endl;
        }
    }
    
    // Thu?t to�n d? quy v� quy ho?ch d?ng
    static int countSelfConjugateDP(int n) {
        // S? d?ng c�ng th?c: s? ph�n ho?ch t? li�n h?p c?a n 
        // = s? ph�n ho?ch c?a n th�nh c�c ph?n l? kh�c nhau
        return countPartitionsIntoDistinctOddParts(n);
    }
    
    // Quy ho?ch d?ng - d?m ph�n ho?ch th�nh c�c ph?n l? kh�c nhau
    static int countPartitionsIntoDistinctOddParts(int n) {
        vector<int> oddParts;
        for (int i = 1; i <= n; i += 2) {
            oddParts.push_back(i);
        }
        
        vector<vector<int>> dp(oddParts.size() + 1, vector<int>(n + 1, 0));
        
        // dp[i][j] = s? c�ch ch?n t? i ph?n t? d?u d? t?ng = j
        for (int i = 0; i <= oddParts.size(); i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= oddParts.size(); i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j];  // Kh�ng ch?n oddParts[i-1]
                if (j >= oddParts[i-1]) {
                    dp[i][j] += dp[i-1][j - oddParts[i-1]];  // Ch?n oddParts[i-1]
                }
            }
        }
        
        return dp[oddParts.size()][n];
    }

private:
    static void generateAllPartitionsWithKParts(int n, int k, int maxVal, 
                                               vector<int>& current, 
                                               vector<vector<int>>& result) {
        if (k == 0) {
            if (n == 0) {
                result.push_back(current);
            }
            return;
        }
        
        if (n <= 0 || maxVal <= 0) return;
        
        for (int i = min(n, maxVal); i >= 1; i--) {
            current.push_back(i);
            generateAllPartitionsWithKParts(n - i, k - 1, i, current, result);
            current.pop_back();
        }
    }
};

// =================== MAIN FUNCTION CHO B�I 3 ===================

int main() {
    cout << "\n=== B�I TO�N 3: PH�N HO?CH T? LI�N H?P ===" << endl << endl;
    
    // Test b�i to�n 3
    int n3 = 7;
    
    // (a) �?m s? ph�n ho?ch t? li�n h?p c� k ph?n
    cout << "Self-conjugate partitions of " << n3 << ":" << endl;
    for (int k = 1; k <= n3; k++) {
        int count = SelfConjugatePartition::countSelfConjugateWithKParts(n3, k);
        cout << "p_" << k << "^selfcje(" << n3 << ") = " << count << endl;
    }
    cout << endl;
    
    // (b) �?m t?ng s? ph�n ho?ch t? li�n h?p
    int totalSelfConj = SelfConjugatePartition::countAllSelfConjugate(n3);
    int totalSelfConjDP = SelfConjugatePartition::countSelfConjugateDP(n3);
    cout << "Total self-conjugate partitions of " << n3 << ":" << endl;
    cout << "Direct count: " << totalSelfConj << endl;
    cout << "DP (distinct odd parts): " << totalSelfConjDP << endl << endl;
    
    // (c) In ra c�c ph�n ho?ch t? li�n h?p
    SelfConjugatePartition::printAllSelfConjugate(n3);
    
    // Th?ng k� cho nhi?u gi� tr? n
    cout << "=== STATISTICS ===" << endl;
    cout << "n\tSelf-conjugate partitions" << endl;
    cout << "--------------------------------" << endl;
    for (int n = 1; n <= 10; n++) {
        int count = SelfConjugatePartition::countSelfConjugateDP(n);
        cout << n << "\t" << count << endl;
    }
    
    // V� d? chi ti?t cho n = 5
    cout << "\n=== DETAILED EXAMPLE: n = 5 ===" << endl;
    SelfConjugatePartition::printAllSelfConjugate(5);
    
    return 0;
}
