#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Giả sử biến chỉ là p, q, r (có thể mở rộng).
// Hàm để đánh giá biểu thức (ví dụ ta viết “hard‑code” mệnh đề của bạn)
// Ở đây mình ví dụ mệnh đề: (p → q) ∧ (¬r ∨ p)    — bạn thay bằng BT 65/66

bool implies(bool a, bool b) {
    return (!a) || b;
}

// Hàm đánh giá mệnh đề cụ thể
bool formula(bool p, bool q, bool r) {
    // ví dụ: (p → q) ∧ (¬r ∨ p)
    bool part1 = implies(p, q);
    bool part2 = (!r) || p;
    return part1 && part2;
}

int main() {
    int n = 3;  // số biến (p, q, r)
    bool sat = false;
    bool bestP, bestQ, bestR;

    for (int ip = 0; ip < 2; ++ip) {
        for (int iq = 0; iq < 2; ++iq) {
            for (int ir = 0; ir < 2; ++ir) {
                bool p = ip;
                bool q = iq;
                bool r = ir;
                if (formula(p, q, r)) {
                    sat = true;
                    bestP = p; bestQ = q; bestR = r;
                    goto done;
                }
            }
        }
    }
done:
    if (sat) {
        cout << "satisfiable\n";
        cout << "One satisfying assignment: p=" << bestP
             << ", q=" << bestQ << ", r=" << bestR << "\n";
    } else {
        cout << "unsatisfiable\n";
    }
    return 0;
}
