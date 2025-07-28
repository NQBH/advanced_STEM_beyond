#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class FerrersDiagramSolver {
private:
    // Biến chính: current - phân hoạch hiện tại trong quá trình sinh
    // result - danh sách tất cả phân hoạch được sinh
    void generatePartitionsRecursive(int n, int k, int minVal, 
                                   vector<int>& current, 
                                   vector<vector<int>>& result) {
        // Base case: chỉ còn 1 phần
        if (k == 1) {
            if (n >= minVal) {
                current.push_back(n);
                result.push_back(current);
                current.pop_back();
            }
            return;
        }
        
        // Recursive case: thử các giá trị từ minVal đến n/k
        // Điều kiện i <= n/k đảm bảo có thể phân phối đều
        for (int i = minVal; i <= n/k; i++) {
            current.push_back(i);
            generatePartitionsRecursive(n - i, k - 1, i, current, result);
            current.pop_back();
        }
    }
    
public:
    // Hàm chính sinh tất cả phân hoạch của n thành k phần
    vector<vector<int>> generatePartitions(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        
        generatePartitionsRecursive(n, k, 1, current, result);
        
        // Sắp xếp các phần theo thứ tự giảm dần (chuẩn partition)
        for (auto& partition : result) {
            sort(partition.rbegin(), partition.rend());
        }
        
        return result;
    }
    
    // Hàm tính conjugate partition
    // conjugate[i] = số phần trong partition gốc có giá trị >= (i+1)
    vector<int> computeConjugate(const vector<int>& partition) {
        if (partition.empty()) return {};
        
        vector<int> conjugate;
        int maxPart = partition[0]; // partition đã được sort giảm dần
        
        // Với mỗi cột i (từ 1 đến maxPart)
        for (int i = 1; i <= maxPart; i++) {
            int count = 0;
            // Đếm số phần >= i
            for (int part : partition) {
                if (part >= i) count++;
                else break; // Tối ưu: dừng sớm vì đã sort
            }
            if (count > 0) {
                conjugate.push_back(count);
            }
        }
        
        return conjugate;
    }
    
    // Hàm vẽ Ferrers diagram
    void drawFerrersDiagram(const vector<int>& partition, const string& title) {
        cout << title << ":" << endl;
        for (int part : partition) {
            for (int i = 0; i < part; i++) {
                cout << "* ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Hàm format partition để in
    string formatPartition(const vector<int>& partition) {
        if (partition.empty()) return "{}";
        
        string result = "(";
        for (size_t i = 0; i < partition.size(); i++) {
            result += to_string(partition[i]);
            if (i < partition.size() - 1) result += ",";
        }
        result += ")";
        return result;
    }
    
    // Hàm giải bài toán 1
    void solveProblem1(int n, int k) {
        cout << "=== BÀI TOÁN 1: FERRERS & FERRERS TRANSPOSE DIAGRAMS ===" << endl;
        cout << "Tham số: n = " << n << ", k = " << k << endl << endl;
        
        // Sinh tất cả phân hoạch
        vector<vector<int>> partitions = generatePartitions(n, k);
        cout << "Số phân hoạch p_k(n) = p_" << k << "(" << n << ") = " 
             << partitions.size() << endl << endl;
        
        // Xử lý từng phân hoạch
        for (size_t i = 0; i < partitions.size(); i++) {
            cout << "--- PHÂN HOẠCH " << (i + 1) << " ---" << endl;
            cout << "λ = " << formatPartition(partitions[i]) << endl << endl;
            
            // Vẽ Ferrers diagram gốc
            drawFerrersDiagram(partitions[i], "Ferrers Diagram F");
            
            // Tính và vẽ conjugate
            vector<int> conjugate = computeConjugate(partitions[i]);
            cout << "Conjugate λ^T = " << formatPartition(conjugate) << endl << endl;
            drawFerrersDiagram(conjugate, "Ferrers Transpose Diagram F^T");
            
            // Kiểm tra tính chất (λ^T)^T = λ
            vector<int> doubleConjugate = computeConjugate(conjugate);
            bool isCorrect = (partitions[i] == doubleConjugate);
            cout << "Kiểm tra (λ^T)^T = λ: " << (isCorrect ? "✓" : "✗") << endl;
            
            cout << string(50, '=') << endl << endl;
        }
    }
};

int main() {
    cout << "CHƯƠNG TRÌNH GIẢI BÀI TOÁN 1: FERRERS & FERRERS TRANSPOSE DIAGRAMS" << endl;
    cout << string(70, '=') << endl << endl;
    
    int n, k;
    cout << "Nhập n (số cần phân hoạch): ";
    cin >> n;
    cout << "Nhập k (số phần): ";
    cin >> k;
    cout << endl;
    
    // Kiểm tra tính hợp lệ
    if (n <= 0 || k <= 0) {
        cout << "Lỗi: n và k phải là số nguyên dương!" << endl;
        return 1;
    }
    
    if (k > n) {
        cout << "Không có phân hoạch nào vì k > n!" << endl;
        return 1;
    }
    
    FerrersDiagramSolver solver;
    solver.solveProblem1(n, k);
    
    // Demo với các test cases
    cout << "\n" << string(70, '=') << endl;
    cout << "DEMO VỚI CÁC TEST CASES KHÁC:" << endl;
    cout << string(70, '=') << endl;
    
    vector<pair<int, int>> testCases = {{4, 2}, {5, 3}, {6, 2}};
    
    for (auto& tc : testCases) {
        cout << "\n";
        solver.solveProblem1(tc.first, tc.second);
    }
    
    return 0;
}