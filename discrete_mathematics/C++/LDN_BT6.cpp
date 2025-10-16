#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    int rule = 1;

    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) {
        p = i; q = j;

        cout << "Rule " << rule++ << ": " << ((p <= q) == (!p || q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((!(p <= q)) == (p && !q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p <= q) == ((!(q)) <= (!(p))) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p || q) == ((!p) <= q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p && q) == (!(p <= (!q))) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p == q) == ((p <= q) && (q <= p)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p == q) == ((!(p)) == (!(q))) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((p == q) == ((p && q) || (!p && !q)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << ((!(p == q)) == (p == (!q)) ? "true" : "false") << endl;
    }

    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
        p = i; q = j; r = k;

        cout << "Rule " << rule++ << ": " << (((p <= q) && (p <= r)) == (p <= (q && r)) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << (((p <= r) && (q <= r)) == ((p || q) <= r) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << (((p <= q) || (r <= q)) == ((p && r) <= q) ? "true" : "false") << endl;
        cout << "Rule " << rule++ << ": " << (((p <= q) || (p <= r)) == (p <= (q || r)) ? "true" : "false") << endl;
    }

    return 0;
}
