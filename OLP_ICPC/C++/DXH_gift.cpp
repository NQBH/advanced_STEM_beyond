#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int t; //t là số lượng dữ liệu cần xử lí
    cin >> t; 
    
    while (t--) {
        int n, k; //n là số lượng quà tặng, k là độ chênh lệch tối thiểu
        cin >> n >> k;
        
        vector<int> gifts(n); 
        for (int i = 0; i < n; ++i) {
            cin >> gifts[i];
        }
        
        vector<int> optimal_sequence;
        
        for (int gift : gifts) {
            
            auto it = upper_bound(optimal_sequence.begin(), optimal_sequence.end(), gift - k);
            
            if (it == optimal_sequence.end()) {
                // Có thể thêm vào cuối dãy
                if (optimal_sequence.empty() || gift > optimal_sequence.back() + (k - 1)) {
                    optimal_sequence.push_back(gift);
                }
            } else {
                // Tối ưu hóa bằng cách thay thế
                if (*it > gift) {
                    *it = gift;
                }
            }
        }
        
        cout << optimal_sequence.size() << '\n';
    }
    
    return 0;
}