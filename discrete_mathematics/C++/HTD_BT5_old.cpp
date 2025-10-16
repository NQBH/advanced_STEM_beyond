#include <iostream>
using namespace std;

// Hàm kiểm tra Modus Ponens: (p → q, p) ⊢ q
bool check_modus_ponens() {
    bool p, q;
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) {
            q = j;
            bool premise1 = (!p) || q;  // p → q
            bool premise2 = p;
            bool conclusion = q;
            if (premise1 && premise2 && !conclusion)
                return false;
        }
    }
    return true;
}

// Các hàm tương tự cho các quy tắc khác...
// Ví dụ:
bool check_modus_tollens() {
    bool p, q;
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) {
            q = j;
            bool premise1 = (!p) || q;  // p → q
            bool premise2 = !q;
            bool conclusion = !p;
            if (premise1 && premise2 && !conclusion)
                return false;
        }
    }
    return true;
}

// Main
int main() {
    cout << "Modus Ponens: " << (check_modus_ponens() ? "✔️ Valid" : "❌ Invalid") << endl;
    cout << "Modus Tollens: " << (check_modus_tollens() ? "✔️ Valid" : "❌ Invalid") << endl;
    // Có thể tiếp tục với các hàm khác tương tự
    return 0;
}
