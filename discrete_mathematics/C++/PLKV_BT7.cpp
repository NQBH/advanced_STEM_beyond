#include <iostream>
using namespace std;

//BÀI 65
bool bt65a(bool p, bool q) {
    return (p || !q) && (!p || q) && (!p || !q);
}

bool bt65b(bool p, bool q) {
    // p -> q tương đương !p || q
    bool a = (!p || q);
    bool b = (!p || !q);
    bool c = (p || !q);
    return a && b && c;
}

bool bt65c(bool p, bool q) {
    // p <-> q tương đương (p && q) || (!p && !q)
    bool bic1 = (p && q) || (!p && !q);
    bool bic2 = (!p && q) || (p && !q);
    return bic1 && bic2;
}

// BÀI 66
bool bt66a(bool p, bool q, bool r, bool s) {
    return (p || q || !r) && (p || !q || !s) && (p || !r || !s)
        && (!p || !q || !s) && (p || q || !s);
}

bool bt66b(bool p, bool q, bool r, bool s) {
    return (!p || !q || r) && (!p || q || !s)
        && (p || !q || !s) && (!p || !r || s) && (p || q || !r);
}

bool bt66c(bool p, bool q, bool r, bool s) {
    return (p || q || r) && (p || !q || !s)
        && (q || !r || s) && (!p || r || s)
        && (!p || q || !s) && (p || !q || !r)
        && (!p || !q || s) && (!p || !r || !s);
}

int main() {
    cout << "===== CHECK SATISFIABILITY =====\n";

    // Bài 65
    cout << "\nBai 65:\n";
    for (int i = 1; i <= 3; i++) {
        bool found = false;
        for (int p = 0; p <= 1; p++)
            for (int q = 0; q <= 1; q++) {
                bool res = (i == 1 ? bt65a(p, q)
                           : i == 2 ? bt65b(p, q)
                                    : bt65c(p, q));
                if (res) {
                    cout << "65" << char('a' + i - 1)
                         << ": satisfiable with p=" << p << ", q=" << q << endl;
                    found = true;
                    break;
                }
            }
        if (!found)
            cout << "65" << char('a' + i - 1) << ": unsatisfiable\n";
    }

    // Bài 66
    cout << "\nBai 66:\n";
    for (int i = 1; i <= 3; i++) {
        bool found = false;
        for (int p = 0; p <= 1; p++)
            for (int q = 0; q <= 1; q++)
                for (int r = 0; r <= 1; r++)
                    for (int s = 0; s <= 1; s++) {
                        bool res = (i == 1 ? bt66a(p, q, r, s)
                                   : i == 2 ? bt66b(p, q, r, s)
                                            : bt66c(p, q, r, s));
                        if (res) {
                            cout << "66" << char('a' + i - 1)
                                 << ": satisfiable with p=" << p
                                 << ", q=" << q
                                 << ", r=" << r
                                 << ", s=" << s << endl;
                            found = true;
                            goto next;
                        }
                    }
        next:
        if (!found)
            cout << "66" << char('a' + i - 1) << ": unsatisfiable\n";
    }
    return 0;
}