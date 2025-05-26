#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    while (true) {
        vector<int> li(15);
        int x;
        int n = 0; // số lượng phần tử thực sự nhập

        // Đọc từng phần tử trong dòng, dừng khi gặp 0 hoặc -1
        for (int i = 0; i < 15; i++) {
            cin >> x;
            if (x == -1) return 0;  // kết thúc toàn bộ chương trình
            if (x == 0) break;      // kết thúc dòng hiện tại
            li[i] = x;
            n++;
        }

        // In ra kiểm tra (có thể bỏ khi không cần)
        // for (int i = 0; i < n; i++) {
        //     cout << li[i] << " ";
        // }
        // cout << endl;

        int dem = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (li[j] == 2 * li[i]) {
                    dem++;
                    break;  // mỗi li[i] đếm 1 lần thôi
                }
            }
        }

        cout << dem << endl;

        // Reset n cho dòng tiếp theo
        n = 0;
    }

    return 0;
}