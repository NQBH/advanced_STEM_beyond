#include <iostream>
using namespace std;

// ======================================================
// Toán tử logic cơ bản
// ======================================================
bool IMP(bool p, bool q) { return !p || q; }                 // p → q
bool BIC(bool p, bool q) { return IMP(p, q) && IMP(q, p); }  // p ↔ q

// ======================================================
// Kiểm tra tất cả quy tắc (dùng hàm lambda ngắn gọn)
// ======================================================
int main() {
    cout << "=== KIỂM TRA LOGIC ROSEN (BẢNG 7 & 8) ===\n\n";

    // Hàm kiểm tra gọn gàng (2 biến p, q)
    auto check = [](string name, string desc, auto expr, string type) {
        bool ok = true;
        for (bool p : {true, false})
            for (bool q : {true, false})
                if (!expr(p, q)) ok = false;
        cout << name << ": " << (ok ? "✅ " : "❌ ") << desc << "  (" << type << ")\n";
    };

    // ======================================================
    // BẢNG 7: TƯƠNG ĐƯƠNG LOGIC
    // ======================================================
    cout << "[ BẢNG 7: TƯƠNG ĐƯƠNG LOGIC ]\n";

    check("Loại bỏ Kéo theo",
          "(p → q) ↔ (¬p ∨ q)",
          [](bool p, bool q){ return BIC(IMP(p, q), (!p || q)); },
          "Equivalence");

    check("Phản đảo",
          "(p → q) ↔ (¬q → ¬p)",
          [](bool p, bool q){ return BIC(IMP(p, q), IMP(!q, !p)); },
          "Equivalence");

    check("Loại bỏ Tương đương",
          "(p ↔ q) ↔ ((p → q) ∧ (q → p))",
          [](bool p, bool q){ return BIC(BIC(p, q), (IMP(p, q) && IMP(q, p))); },
          "Equivalence");

    // ======================================================
    // BẢNG 8: QUY TẮC SUY LUẬN
    // ======================================================
    cout << "\n[ BẢNG 8: QUY TẮC SUY LUẬN ]\n";

    check("Modus Ponens",
          "((p → q) ∧ p) → q",
          [](bool p, bool q){ return IMP((IMP(p, q) && p), q); },
          "Tautology");

    check("Modus Tollens",
          "((p → q) ∧ ¬q) → ¬p",
          [](bool p, bool q){ return IMP((IMP(p, q) && !q), !p); },
          "Tautology");

    check("Disjunctive Syllogism",
          "((p ∨ q) ∧ ¬p) → q",
          [](bool p, bool q){ return IMP(((p || q) && !p), q); },
          "Tautology");

    check("Simplification",
          "(p ∧ q) → p",
          [](bool p, bool q){ return IMP((p && q), p); },
          "Tautology");

    // ======================================================
    // Quy tắc 3 biến: Hypothetical Syllogism
    // ======================================================
    cout << "\n[ Quy tắc 3 biến: Hypothetical Syllogism ]\n";
    cout << "(((p → q) ∧ (q → r)) → (p → r))\n";

    bool hs = true;
    for (int i = 0; i < 8; ++i) {
        bool p = (i & 4) != 0;
        bool q = (i & 2) != 0;
        bool r = (i & 1) != 0;
        if (!IMP((IMP(p, q) && IMP(q, r)), IMP(p, r))) {
            hs = false;
            break;
        }
    }
    cout << "Hypothetical Syllogism: " << (hs ? "✅ CHÍNH XÁC (Tautology)" : "❌ SAI") << '\n';
    return 0;
}
