#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class FerrersDiagram {
private:
    vector<int> partition;
    int n;
    
public:
    // Constructor t? phân ho?ch
    FerrersDiagram(vector<int> p) {
        partition = p;
        sort(partition.rbegin(), partition.rend()); // S?p x?p gi?m d?n
        n = 0;
        for (int x : partition) n += x;
    }
    
    // T?o phân ho?ch t? s? n
    static vector<vector<int>> generatePartitions(int n) {
        vector<vector<int>> result;
        vector<int> current;
        generatePartitionsHelper(n, n, current, result);
        return result;
    }
    
private:
    static void generatePartitionsHelper(int n, int maxVal, vector<int>& current, vector<vector<int>>& result) {
        if (n == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = min(n, maxVal); i >= 1; i--) {
            current.push_back(i);
            generatePartitionsHelper(n - i, i, current, result);
            current.pop_back();
        }
    }
    
public:
    // Tính bi?u d? Ferrers chuy?n v?
    FerrersDiagram transpose() {
        if (partition.empty()) return FerrersDiagram({});
        
        int maxPart = partition[0];
        vector<int> transposed(maxPart, 0);
        
        for (int part : partition) {
            for (int i = 0; i < part; i++) {
                transposed[i]++;
            }
        }
        
        return FerrersDiagram(transposed);
    }
    
    // Hi?n th? bi?u d? Ferrers
    void display() {
        cout << "Partition: ";
        for (int i = 0; i < partition.size(); i++) {
            cout << partition[i];
            if (i < partition.size() - 1) cout << " + ";
        }
        cout << " = " << n << endl;
        
        cout << "Ferrers diagram:" << endl;
        for (int part : partition) {
            for (int i = 0; i < part; i++) {
                cout << "* ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // L?y phân ho?ch
    vector<int> getPartition() const {
        return partition;
    }
    
    // Ki?m tra t? d?i ng?u (self-conjugate)
    bool isSelfConjugate() {
        FerrersDiagram t = transpose();
        return partition == t.partition;
    }
    
    // Tính s? hàng và c?t
    pair<int, int> getDimensions() {
        if (partition.empty()) return {0, 0};
        int rows = partition.size();
        int cols = partition[0];
        return {rows, cols};
    }
};

// Hàm tính p_k(n) - s? phân ho?ch c?a n thành dúng k ph?n
int countPartitionsWithKParts(int n, int k) {
    if (k > n || k <= 0) return 0;
    if (k == 1) return 1;
    
    // DP: dp[i][j] = s? cách phân ho?ch i thành j ph?n
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
        }
    }
    
    return dp[n][k];
}

// Hàm tính t?ng s? phân ho?ch c?a n
int countTotalPartitions(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }
    
    return dp[n];
}

// Ki?m tra bijection gi?a Ferrers và Ferrers transpose
void verifyBijection(int n) {
    cout << "=== Verification of Ferrers-Transpose Bijection for n = " << n << " ===" << endl;
    
    auto partitions = FerrersDiagram::generatePartitions(n);
    map<vector<int>, vector<int>> ferrersToTranspose;
    set<vector<int>> allTransposes;
    
    cout << "All partitions of " << n << ":" << endl;
    for (auto& p : partitions) {
        FerrersDiagram f(p);
        FerrersDiagram ft = f.transpose();
        
        ferrersToTranspose[f.getPartition()] = ft.getPartition();
        allTransposes.insert(ft.getPartition());
        
        cout << "F: ";
        for (int x : f.getPartition()) cout << x << " ";
        cout << "-> F^T: ";
        for (int x : ft.getPartition()) cout << x << " ";
        
        if (f.isSelfConjugate()) {
            cout << " (self-conjugate)";
        }
        cout << endl;
    }
    
    cout << "\nTotal partitions: " << partitions.size() << endl;
    cout << "Unique transposes: " << allTransposes.size() << endl;
    cout << "Bijection verified: " << (partitions.size() == allTransposes.size() ? "YES" : "NO") << endl;
    cout << endl;
}

int main() {
    cout << "=== FERRERS DIAGRAMS & TRANSPOSE BIJECTION ===" << endl << endl;
    
    // Ví d? v?i n = 4
    cout << "Example with n = 4:" << endl;
    vector<int> example = {3, 1};
    FerrersDiagram f(example);
    f.display();
    
    cout << "Transpose:" << endl;
    FerrersDiagram ft = f.transpose();
    ft.display();
    
    // Ki?m tra bijection cho các giá tr? n nh?
    for (int n = 1; n <= 6; n++) {
        verifyBijection(n);
    }
    
    // Tính p_k(n) cho m?t s? tru?ng h?p
    cout << "=== Partition counts p_k(n) ===" << endl;
    for (int n = 1; n <= 8; n++) {
        cout << "n = " << n << ": ";
        for (int k = 1; k <= n; k++) {
            cout << "p_" << k << "(" << n << ") = " << countPartitionsWithKParts(n, k) << "  ";
        }
        cout << "| Total: " << countTotalPartitions(n) << endl;
    }
    
    // Ví d? interactive
    cout << "\n=== Interactive Example ===" << endl;
    cout << "Enter a partition (e.g., 4 2 1 for 4+2+1): ";
    vector<int> userPartition;
    int part;
    
    // Ð?c phân ho?ch t? user (có th? c?i ti?n thêm)
    cout << "Using example partition: 4 2 2 1" << endl;
    userPartition = {4, 2, 2, 1};
    
    FerrersDiagram userF(userPartition);
    cout << "\nYour Ferrers diagram:" << endl;
    userF.display();
    
    FerrersDiagram userFT = userF.transpose();
    cout << "Transpose:" << endl;
    userFT.display();
    
    auto dims = userF.getDimensions();
    auto dimst = userFT.getDimensions();
    cout << "Original dimensions: " << dims.first << " x " << dims.second << endl;
    cout << "Transpose dimensions: " << dimst.first << " x " << dimst.second << endl;
    
    if (userF.isSelfConjugate()) {
        cout << "This partition is self-conjugate!" << endl;
    }
    
    return 0;
}
