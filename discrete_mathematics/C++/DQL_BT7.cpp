#include <iostream>
using namespace std;
int main() {
    bool p, q, r, s;
    bool sat;
    cout << "===== BAI 65 =====\n";
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            bool expr = (p || !q) && (!p || q) && (!p || !q);
            if (expr) {
                sat = true;
                cout << "65a: satisfiable, p =" << p << ", q =" << q << endl;
                goto next65a;
            }
        }
    cout << "65a: unsatisfiable\n";
next65a:;
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            bool expr = ((!p || q) && (!p || !q) && (p || q) && (p || !q));
            if (expr) {
                sat = true;
                cout << "65b: satisfiable, p =" << p << ", q =" << q << endl;
                goto next65b;
            }
        }
    cout << "65b: unsatisfiable\n";
next65b:;
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            bool expr = ((p == q) && ((!p) == q));
            if (expr) {
                sat = true;
                cout << "65c: satisfiable, p =" << p << ", q =" << q << endl;
                goto next65c;
            }
        }
    cout << "65c: unsatisfiable\n";
next65c:;
    cout << "\n===== BAI 66 =====\n";
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                for (int t = 0; t <= 1; t++) {
                    p = i; q = j; r = k; s = t;
                    bool expr =
                        (p || q || !r) &&
                        (p || !q || !s) &&
                        (p || !r || !s) &&
                        (!p || !q || !s) &&
                        (p || q || !s);
                    if (expr) {
                        sat = true;
                        cout << "66a: satisfiable, p =" << p << ", q =" << q
                             << ", r=" << r << ", s =" << s << endl;
                        goto next66a;
                    }
                }
    cout << "66a: unsatisfiable\n";
next66a:;
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                for (int t = 0; t <= 1; t++) {
                    p = i; q = j; r = k; s = t;
                    bool expr =
                        (!p || !q || r) &&
                        (!p || q || !s) &&
                        (p || q || r) &&
                        (p || q || !s) &&
                        (p || !r || !s);
                    if (expr) {
                        sat = true;
                        cout << "66b: satisfiable, p =" << p << ", q =" << q
                             << ", r =" << r << ", s =" << s << endl;
                        goto next66b;
                    }
                }
    cout << "66b: unsatisfiable\n";
next66b:;
    sat = false;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                for (int t = 0; t <= 1; t++) {
                    p = i; q = j; r = k; s = t;
                    bool expr =
                        (p || q || r) &&
                        (p || !q || !s) &&
                        (q || !r || s) &&
                        (!p || r || s) &&
                        (!p || q || !s) &&
                        (p || !q || !r) &&
                        (!p || !q || s) &&
                        (!p || !r || !s);
                    if (expr) {
                        sat = true;
                        cout << "66c: satisfiable, p =" << p << ", q =" << q
                             << ", r =" << r << ", s =" << s << endl;
                        goto next66c;
                    }
                }
    cout << "66c: unsatisfiable\n";
next66c:;
}