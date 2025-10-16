#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    int rule = 1;

    for (int i = 0; i < 2; ++i) {
        p = i;
        cout << "Rule " << rule++ << ": " << ((p && true) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || false) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || true) == true ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && false) == false ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || p) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && p) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((!(!p)) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || !p) == true ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && !p) == false ? "true" : "false") << endl;
    }

    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) {
        p = i; q = j;
        cout << "Rule " << rule++ << ": " << ((p || q) == (q || p) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && q) == (q && p) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((!(p && q)) == (!p || !q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((!(p || q)) == (!p && !q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || (p && q)) == p ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && (p || q)) == p ? "true" : "false") << endl;
    }

    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
        p = i; q = j; r = k;
        cout << "Rule " << rule++ << ": " << (((p || q) || r) == (p || (q || r)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << (((p && q) && r) == (p && (q && r)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || (q && r)) == ((p || q) && (p || r)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && (q || r)) == ((p && q) || (p && r)) ? "true" : "false") << endl;
    }

    return 0;
}
