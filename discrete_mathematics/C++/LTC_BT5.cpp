#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool T = true;
    bool F = false;

    cout << "=== KIEM TRA CAC QUY TAC LOGIC (Table 6 - Rosen 2019) ===\n\n";

    // 1. Identity laws
    cout << "1. Identity laws\n";
    cout << "p\t(p ? T)\t(p ? F)\n";
    for (int i = 0; i <= 1; i++) {
        p = i;
        cout << p << "\t" << (p && T) << "\t" << (p || F) << endl;
    }
    cout << endl;

    // 2. Domination laws
    cout << "2. Domination laws\n";
    cout << "p\t(p ? T)\t(p ? F)\n";
    for (int i = 0; i <= 1; i++) {
        p = i;
        cout << p << "\t" << (p || T) << "\t" << (p && F) << endl;
    }
    cout << endl;

    // 3. Idempotent laws
    cout << "3. Idempotent laws\n";
    cout << "p\t(p ? p)\t(p ? p)\n";
    for (int i = 0; i <= 1; i++) {
        p = i;
        cout << p << "\t" << (p || p) << "\t" << (p && p) << endl;
    }
    cout << endl;

    // 4. Double negation
    cout << "4. Double negation law\n";
    cout << "p\t¬(¬p)\n";
    for (int i = 0; i <= 1; i++) {
        p = i;
        cout << p << "\t" << (!(!p)) << endl;
    }
    cout << endl;

    // 5. Commutative laws
    cout << "5. Commutative laws\n";
    cout << "p\tq\t(p ? q)\t(q ? p)\t(p ? q)\t(q ? p)\n";
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            cout << p << "\t" << q << "\t" << (p || q) << "\t" << (q || p)
                 << "\t" << (p && q) << "\t" << (q && p) << endl;
        }
    }
    cout << endl;

    // 6. Associative laws
    cout << "6. Associative laws\n";
    cout << "p\tq\tr\t((p ? q) ? r)\t(p ? (q ? r))\t((p ? q) ? r)\t(p ? (q ? r))\n";
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                cout << p << "\t" << q << "\t" << r << "\t"
                     << ((p || q) || r) << "\t\t"
                     << (p || (q || r)) << "\t\t"
                     << ((p && q) && r) << "\t\t"
                     << (p && (q && r)) << endl;
            }
        }
    }
    cout << endl;

    // 7. Distributive laws
    cout << "7. Distributive laws\n";
    cout << "p\tq\tr\t(p ? (q ? r))\t((p ? q) ? (p ? r))\t(p ? (q ? r))\t((p ? q) ? (p ? r))\n";
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                cout << p << "\t" << q << "\t" << r << "\t"
                     << (p || (q && r)) << "\t\t"
                     << ((p || q) && (p || r)) << "\t\t"
                     << (p && (q || r)) << "\t\t"
                     << ((p && q) || (p && r)) << endl;
            }
        }
    }
    cout << endl;

    // 8. De Morgan’s laws
    cout << "8. De Morgan's laws\n";
    cout << "p\tq\t¬(p ? q)\t(¬p ? ¬q)\t¬(p ? q)\t(¬p ? ¬q)\n";
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            cout << p << "\t" << q << "\t"
                 << (!(p && q)) << "\t\t"
                 << ((!p) || (!q)) << "\t\t"
                 << (!(p || q)) << "\t\t"
                 << ((!p) && (!q)) << endl;
        }
    }
    cout << endl;

    // 9. Absorption laws
    cout << "9. Absorption laws\n";
    cout << "p\tq\t(p ? (p ? q))\t(p ? (p ? q))\n";
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            cout << p << "\t" << q << "\t"
                 << (p || (p && q)) << "\t\t"
                 << (p && (p || q)) << endl;
        }
    }
    cout << endl;

    // 10. Negation laws
    cout << "10. Negation laws\n";
    cout << "p\t(p ? ¬p)\t(p ? ¬p)\n";
    for (int i = 0; i <= 1; i++) {
        p = i;
        cout << p << "\t" << (p || !p) << "\t\t" << (p && !p) << endl;
    }

    return 0;
}
