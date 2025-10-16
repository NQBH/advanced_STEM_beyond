#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool ans;
    cout << "Table 7: Conditional Statements\n";
    //quy tac 1: p -> q = !p || q
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = (!p || q);
            bool right = (!p || q);
            if (left != right) ans = 0;
        }
    }
    cout << "1.p -> q = !p || q: " << ans << endl;
    //quy tac 2: p -> q = !q -> !p
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = (!p || q);
            bool right = (q || !p);
            if (left != right) ans = 0;
        }
    }
    cout << "2.p -> q = !q -> !p: " << ans << endl;
    //quy tac 3: p || q = !p -> q
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; Q++) {
            q = Q;
            bool left = (p || q);
            bool right = (p || q);
            if (left != right) ans = 0;
        }
    }
    cout << "3.p or q = !p -> q: " << ans << endl;
    //quy tac 4: p && q = !(p -> !q)
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = (p && q);
            bool right = !(!p || !q);
            if (left != right) ans = 0;
        }
    }
    cout << "4.p and q = !(p -> !q): " << ans << endl;
    //quy tac 5: !(p -> q) = p && !q
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = !(!p || q);
            bool right = (p && !q);
            if (left != right) ans = 0;
        }
    }
    cout << "5.!(p -> q) = p && !q: " << ans << endl;
    // quy tac 6: (p->q) && (p->r) = p -> (q && r)
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            for (int R = 0; R < 2; ++R) {
                r = R;
                bool left = ((!p || q) && (!p || r));
                bool right = (!p || (q && r));
                if (left != right) ans = 0;
            }
        }
    }
    cout << "6. (p -> q) && (p -> r) = p -> (q && r): " << ans << endl;
    //quy tac 7: (p->r) and (q->r) = (p or q) -> r
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            for (int R = 0; R < 2; ++R) {
                r = R;
                bool left = ((!p || r) && (!q || r));
                bool right = (!(p || q) || r);
                if (left != right) ans = 0;
            }
        }
    }
    cout << "7. (p->r) && (q->r) = (p || q) -> r: " << ans << endl;
    //quy tac 8: (p -> q) && (q -> r) = p -> r
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            for (int R = 0; R < 2; ++R) {
                r = R;
                bool left = ((!p || q) && (!q || r));
                bool right = (!p || r);
                if (left != right) ans = 0;
            }
        }
    }
    cout << "8.(p -> q) && (q -> r) = p -> r: " << ans << endl;

    //quy tac 9: (p -> r) || (q->r) = (p && q) -> r
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            for (int R= 0; R < 2; ++R) {
                r = R;
                bool left = ((!p || r) || (!q || r));
                bool right = (!(p && q) || r);
                if (left != right) ans = 0;
            }
        }
    }
    cout << "9. (p -> r) || (q -> r) = (p && q) -> r: " << ans << endl;
    cout << "Table 8: Biconditional Statements\n";
    //quy tac 1: p <-> q == (p -> q) && (q->p)
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = ((!p || q) && (!q || p));
            bool right = ((!p || q) && (!q || p));
            if (left != right) ans = 0;
        }
    }
    cout << "1. p <-> q = (p->q) && (q->p): " << ans << endl;
    //quy tac 2: p <-> q == !p <-> !q
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = ((!p || q) && (!q || p));
            bool right = ((p || !q) && ( q || !p));
            if (left != right) ans = 0;
        }
    }
    cout << "2.p <-> q = !p <-> !q: " << ans << endl;
//quy tac 3: p <-> q == (p && q) || (!p && !q)
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = ((!p || q) && (!q || p));
            bool right = ((p && q) || (!p && !q));
            if (left != right) ans = 0;
        }
    }
    cout << "3.p <-> q = (p && q) || (!p && !q): " << ans << endl;
//quy tac 4: !(p <-> q) == p <-> !q
    ans = 1;
    for (int P = 0; P < 2; ++P) {
        p = P;
        for (int Q = 0; Q < 2; ++Q) {
            q = Q;
            bool left = !((!p || q) && (!q || p));
            bool right = ((!p || !q) && (q || p)) ;
            if (left != right) ans = 0;
        }
    }
    cout << "4.!(p <-> q) == p <-> !q: " << ans << endl;
}