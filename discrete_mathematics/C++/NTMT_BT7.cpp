#include <iostream>
using namespace std;
int main() {
    bool p, q, r, s, satisfiable = 0, e1 = 1;

    //65.a
    cout << "Bai 65a" << endl;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p || !q) && (!p || q) && (!p || !q)) {
                satisfiable = 1;
                cout << "satisfiable \n" << "(p;q) = (" << p << ";" << q << ")" << endl;
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;

    //65b.
    satisfiable = 0;
    cout << "\n" << "Bai 65b" << endl;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((!p || q) && (!p || !q) && (p || q) && (p || !q)) {
                satisfiable = 1;
                cout << "satisfiable \n" << "(p;q) = (" << p << ";" << q << ")" << endl;
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;

    //65.c
    satisfiable = 0;
    cout << "\nBai 65c" << endl;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if (((!p || q) && (!q || p)) && ((p || q) && (!p || !q))) {
                satisfiable = 1;
                cout << "satisfiable \n (p;q) = " << "(" << p << ";" << q << ")" << endl;
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;

    //66.a
    cout << "\nBai 66a" << endl;
    satisfiable = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int h = 0; h <= 1; ++h) {
                    p = i; q = j; r = k; s = h;
                    if ((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
                        satisfiable = 1;
                        cout << "satisfiable \n (p,q,r,s) = (" << p << "," << q << "," << r << "," << s << ")" << endl;
                    }
                }
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;

    //66.b
    cout << "\nBai 66b" << endl;
    satisfiable = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int h = 0; h <= 1; ++h) {
                    p = i; q = j; r = k; s = h;
                    if ((!p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && (p || !r || !s)) {
                        satisfiable = 1;
                        cout << "satisfiable \n(p,q,r,s) = (" << p << "," << q << "," << r << "," << s << ")" << endl;
                    }
                }
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;

    //Bai 66.c
    cout << "\nBai 66c" << endl;
    satisfiable = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int h = 0; h <= 1; ++h) {
                    p = i; q = j; r = k; s = h;
                    if ((p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s)) {
                        satisfiable = 1;
                        cout << "satisfiable \n(p,q,r,s) = (" << p << "," << q << "," << r << "," << s << ")" << endl;
                    }
                }
            }
        }
    }
    if (satisfiable == 0) cout << "unsatisfiable" << endl;
    return 1;
}