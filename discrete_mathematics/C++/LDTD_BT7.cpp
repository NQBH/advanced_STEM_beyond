#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "===== BAI 65 =====" << endl;
    // Các biến: p, q
    for (int i = 0; i < 3; i++) {
        bool found = false;
        bool p, q;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                p = a; 
                q = b;
                bool result = false;

                switch (i) {
                    case 0: // (p ∨ ¬q) ∧ (¬p ∨ q) ∧ (¬p ∨ ¬q)
                        result = ((p || !q) && (!p || q) && (!p || !q));
                        break;

                    case 1: // (p → q) ∧ (p → ¬q) ∧ (¬p → q) ∧ (¬p → ¬q)
                        // Thay p → q bằng (!p || q)
                        result = ((!p || q) && (!p || !q) && (p || q) && (p || !q));
                        break;

                    case 2: // (p ↔ q) ∧ (¬p ↔ q)
                        // Thay p ↔ q bằng (p == q)
                        result = ((p == q) && ((!p) == q));
                        break;
                }

                if (result) {
                    cout << "65" << char('a' + i) 
                         << ": satisfiable with p=" << p << ", q=" << q << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found)
            cout << "65" << char('a' + i) << ": unsatisfiable" << endl;
    }

    cout << "\n===== BAI 66 =====" << endl;
    // Các biến: p, q, r, s
    for (int i = 0; i < 3; i++) {
        bool found = false;
        bool p, q, r, s;

        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                for (int c = 0; c < 2; c++)
                    for (int d = 0; d < 2; d++) {
                        p = a; q = b; r = c; s = d;
                        bool result = false;

                        switch (i) {
                            case 0: // (p ∨ q ∨ ¬r) ∧ (p ∨ ¬q ∨ ¬s) ∧ (p ∨ ¬r ∨ ¬s) ∧ (¬p ∨ ¬q ∨ ¬s) ∧ (p ∨ q ∨ ¬s)
                                result = ((p||q||!r) && (p||!q||!s) && (p||!r||!s) && (!p||!q||!s) && (p||q||!s));
                                break;

                            case 1: // (¬p ∨ ¬q ∨ r) ∧ (¬p ∨ q ∨ ¬s) ∧ (p ∨ ¬q ∨ ¬s) ∧ (¬p ∨ ¬r ∨ ¬s) ∧ (p ∨ q ∨ ¬r)
                                result = ((!p||!q||r) && (!p||q||!s) && (p||!q||!s) && (!p||!r||!s) && (p||q||!r));
                                break;

                            case 2: // Bài 66c
                                result = ((p||q||r) && (p||!q||!s) && (q||!r||s) &&
                                          (!p||r||s) && (!p||q||!s) && (p||!q||!r) &&
                                          (!p||!q||s) && (!p||!r||!s));
                                break;
                        }

                        if (result) {
                            cout << "66" << char('a' + i)
                                 << ": satisfiable with p=" << p 
                                 << ", q=" << q 
                                 << ", r=" << r 
                                 << ", s=" << s << endl;
                            found = true;
                            goto next_formula;
                        }
                    }

        next_formula:
        if (!found)
            cout << "66" << char('a' + i) << ": unsatisfiable" << endl;
    }

    return 0;
}
