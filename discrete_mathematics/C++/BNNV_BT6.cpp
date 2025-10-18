#include <iostream>
using namespace std;

int main () {
    bool p, q, r;
    bool ans = 0;
//table 7
    cout << "Table 7\n";

//p -> q = !p or !q
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left = !p || q;
        bool right = p || !q;
        if (left == right);
        ans = 1;
    }
    cout << "p -> q = !p or !q: " << ans << endl;

//p -> q = !q -> !p
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left = !p || q;
        bool right = !q || p;
        if (left == right);
        ans = 1;
    }
    cout << "p -> q = !q -> !p: " << ans << endl;

//p or q = !p -> q
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left = p || q;
        bool right = p || q;
        if (left == right);
        ans = 1;
    }
    cout << "p or q = !p -> q: " << ans << endl;

//p and q = !(p -> !q)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left = p && q;
        bool right = !(!p || !q);
        if (left == right);
        ans = 1;
    }
    cout << "p and q = !(p -> !q): " << ans << endl;

//!(p -> q) = p and !q
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left = !(!p || q);
        bool right = !p && !q;
        if (left == right);
        ans = 1;
    }
    cout << "!(p -> q) = p and !q: " << ans << endl << endl;

//(p -> q) and (p -> r) = p -> (q and r)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;
        for (int k = 0; k < 2; ++k)
            r = k;

        bool left =  (!p || q) && ( !p || r) ;
        bool right =  !p || (q && r) ;
        if (left == right);
        ans = 1;
    }
    cout << "(p -> q) and (p -> r) = p -> (q and r): " << ans << endl;

//(p -> r) and (q -> r) = (p or q) -> r
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;
        for (int k = 0; k < 2; ++k)
            r = k;

        bool left =  (!p || r) && (q || r) ;
        bool right =  (!p || q) || r ;
        if (left == right);
        ans = 1;
    }
    cout << "(p -> r) and (q -> r) = (p || q) -> r: " << ans << endl;

//(p -> q) or (p -> r) = p -> (q or r)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;
        for (int k = 0; k < 2; ++k)
            r = k;

        bool left =  (!p || q) || (!p || r) ;
        bool right =  p || (q || r);
        if (left == right);
        ans = 1;
    }
    cout << "(p -> q) or (p -> r) = p -> (q or r): " << ans << endl;

//(p -> r) or (q -> r) = (p and q) -> r
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;
        for (int k = 0; k < 2; ++k)
            r = k;

        bool left =  (!p || r) ||  (q || r) ;
        bool right =  (!p && q) || r ;
        if (left == right);
        ans = 1;
    }
    cout << "(p -> r) and (q -> r) = (p || q) -> r: " << ans << endl << endl;

//table 8
    cout << "Table 8\n";

//p <-> q = (p -> q) and (p -> q)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left =  p || q;
        bool right =  (!p || q) && (p || q);
        if (left == right);
        ans = 1;
    }
    cout << "p <-> q = (p -> q) and (p -> q): " << ans << endl;

//p <-> q = !p <-> !q
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left =  p || q;
        bool right =  p || q && !p || !q;
        if (left == right);
        ans = 1;
    }
    cout << "p <-> q = !p <-> !q: " << ans << endl;

//p <-> q = (p and q) or (!p <-> !q)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left =  p || q;
        bool right =  (p && q) || (!p || !q);
        if (left == right);
        ans = 1;
    }
    cout << "p <-> q = (p and q) or (!p <-> !q): " << ans << endl;

//!(p <-> q) = p <-> !q
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j)
            q = j;

        bool left =  !(p || q);
        bool right = p || !q;
        if (left == right);
        ans = 1;
    }
    cout << "!(p <-> q) = p <-> !q: " << ans << endl;
}