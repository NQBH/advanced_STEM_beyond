#include <iostream>
using namespace std;

// --- Bài 65 ---
bool expr65a(bool p, bool q) {
    //(bool p ,bool q): mình thử các giá trị đúng/sai cho p và q .
    return (p || !q) && (!p || q) && (!p || !q);
    // return : trả về kết quả đ&s
}

bool expr65b(bool p, bool q) {
    return (!p || q) && (!p || !q) && (p || q) && (p || !q);
}

bool expr65c(bool p, bool q) {
    return (p == q) && ((!p) == q);
}

void check65() {
    cout << "--- Bài 65 ---\n";
    for (int i = 0; i < 3; ++i) {
        // mình kiểm tra 3 biểu thức
        bool found = false;
        for (int v = 0; v < 4; ++v) {
            //4 cách gán giá trị cho p và q (đ/s)
            bool p = v & 1;
            bool q = v & 2;
            // lấy bit 2 bool để biết đ/s
            bool result = (i == 0) ? expr65a(p, q) :
                          (i == 1) ? expr65b(p, q) :
                                     expr65c(p, q);
                        // gọi expr65 0>a,1>b,còn lại>c
            if (result) {
                cout << "65" << char('a'+i) << ": satisfiable with p=" << p << ", q=" << q << "\n";
                // (char('a'+i)) chuyển số 0,1,2 thành chữ a,b,c.
                found = true;
                //nếu đúng ra "satisfiable"
                break;
            }
        }
        if (!found) cout << "65" << char('a'+i) << ": unsatisfiable\n";
        // không tìm đc gì ra "unsatisfiable"
    }
}

// --- Bài 66 ---
bool expr66a(bool p, bool q, bool r, bool s) {
    return (p || q || r) &&
           (p || !q || !s) &&
           (p || !r || !s) &&
           (!p || !q || s) &&
           (q || q || s);
}

bool expr66b(bool p, bool q, bool r, bool s) {
    return (!p || !q || r) &&
           (!p || q || !s) &&
           (p || q || !s) &&
           (!p || !q || s) &&
           (p || q || s);
}

bool expr66c(bool p, bool q, bool r, bool s) {
    return (p || q || r) &&
           (p || !q || !s) &&
           (q || !r || s) &&
           (!p || !r || s) &&
           (p || !q || !s) &&
           (!p || !q || s) &&
           (p || q || !r) &&
           (!p || q || s) &&
           (p || q || !s);
}

void check66() {
    cout << "\n--- Bài 66 ---\n";
    for (int i = 0; i < 3; ++i) {
        bool found = false;
        for (int v = 0; v < 16; ++v) {
            bool p = v & 1;
            bool q = v & 2;
            bool r = v & 4;
            bool s = v & 8;
            // v & n -> là lấy từng biến 
            bool result = (i == 0) ? expr66a(p, q, r, s) :
                          (i == 1) ? expr66b(p, q, r, s) :
                                     expr66c(p, q, r, s);
            if (result) {
                cout << "66" << char('a'+i) << ": satisfiable with p=" << p
                     << ", q=" << q << ", r=" << r << ", s=" << s << "\n";
                found = true; // tìm đc 
                break;
            }
        }
        if (!found) cout << "66" << char('a'+i) << ": unsatisfiable\n"; // mất tích
    }
}

// ---- HÀM CHÍNH ----
int main() {
    check65();
    check66();
    // check là để kiểm tra lại 2 bài 
    return 0;
}