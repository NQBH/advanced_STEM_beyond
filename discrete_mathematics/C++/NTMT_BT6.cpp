#include <iostream>
using namespace std;
int main() {
    bool p, q, r, left, right, ans = 1;

    //Bai 6

    //1.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1 ; ++j) {
            p = i;
            q = j;
            left = 1;
            if (p == 1 && q == 0) left = 0;
            if (left != (!p || q)) ans = 0;
        }
    }
    cout << "p->q ~ (not p) or q is " << ans << endl;

    //2.
    for (int i = 0; i <= 1 ; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i;
            q = j;
            left = right = 1;
            if (p == 1 && q == 0) left = 0;
            if (!q == 1 && !p == 0) right = 0;
            if (left != right) ans = 0;
        }
    }
    cout << "p -> q ~ not q -> not p is " << ans << endl;

    //3.
    for (int i = 0 ; i <= 1 ; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i;
            q = j;
            right = 1;
            if (p == 0 && q == 0) right = 0;
            if ((p || q) != right) ans = 0;
        }
    }
    cout << "p or q ~ (not p) -> q is " << ans << endl;

    //4.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i;
            q = j;
            right = 1;
            if (p == 1 && !q == 0) right = 0;
            if ((p && q) != !right) ans = 0;
        }
    }
    cout << "p and q ~ not (p-> (not q)) is " << ans << endl;

    //5.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i;
            q = j;
            left = 1;
            if (p == 1 && q == 0) left = false;
            if (!left != (p && !q)) ans = false;
        }
    }
    cout << "not (p -> q) ~ p and (not q) is " << ans << endl;

    //6.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                left = right = 1;
                if ((p == 1 && q == 0) || (p == 1 && r == 0)) left = 0;
                if (p == 1 && ((q && r) == 0)) right = 0;
                if (left != right) ans = 0;
            }
        }
    }
    cout << "(p -> q) and (p -> r) ~ p -> (q and r) is " << ans << endl;

    //7.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                left = right = 1;
                if ((p == 1 && r == 0) || (q == 1 && r == 0)) left = 0;
                if ((p || q) == 1 && r == 0) right = 0;
                if (left != right) ans = 0;
            }
        }
    }
    cout << "(p -> r) and (q -> r) ~ (p or q) -> r is " << ans << endl;

    //8.
    for (int i = 0; i <= 1; ++i) {
        for (int j; j <= 1; ++j) {
            for (int k; k <= 1; ++k) {
                p = i; q = j; r = k;
                right = left = 1;
                if ((p == 1 && q == 0) && (p == 1 && r == 0)) left = 0;
                if (p == 1 && (q || r) == 0 ) right = 0;
                if (right != left) ans = 0;
            }
        }
    }
    cout << "(p -> q) or (p -> r) ~ p -> (q or r) is " << ans << endl;

    //9.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                right = left = 1;
                if ((p == 1 && r == 0) && (q == 1 && r == 0)) left = 0;
                if (((p && q) == 1) && (r == 0)) right = 0;
                if (left != right) ans = 0;
            }
        }
    }
    cout << "(p -> r) or (q -> r) ~ (p and q) -> r is " << ans << endl;



    //Bai 7



    //1.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            right = left = 1;
            if (p != q) left = 0;
            if ((p == 1 && q == 0) || (!p == 1 && !q == 0)) right = 0;
            if (left != right) ans = 0;
        }
    }
    cout << "p <-> q ~ (p -> q) and (q -> p) is " << ans << endl;

    //2.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if (p != q) left = 0;
            if (!p != !q) right = 0;
            if (left != right) ans = 0;
        }
    }
    cout << "(p <-> q) ~ (not p) <-> (not q) is " << ans << endl;

    //3.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            left = right = 1;
            if (p != q) left = 0;
            if (((p && q) == 0) && ((!p && !q) == 0)) right = 0;
            if (left != right) ans = 0;
        }
    }
    cout << "(p <-> q) ~ (p and q) or ((not p) and (not q)) is " << ans << endl;

    //4.
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            right = left = 1;
            if (p != q) left = 0;
            if (p != !q) right = 0;
            if (!left != right) ans = 0;
        }
    }
    cout << "not (p <-> q) ~ (p <-> not q) is " << ans << endl;
    return 1;
}