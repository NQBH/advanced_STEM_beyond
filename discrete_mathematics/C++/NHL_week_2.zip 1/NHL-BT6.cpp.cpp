/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
using namespace std;

bool imp(bool p, bool q) { return !p || q; }  // p → q
bool iff(bool p, bool q) { return p == q; }   // p ↔ q

int main() {
    bool p, q, r, ans;

    // 7
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (imp(p, q) != (!p || q)) ans = false;
        }
    cout << "p -> q ≡ ¬p v q : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++) for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (imp(p, q) != imp(!q, !p)) ans = false;
        }
    cout << "p -> q ≡ ¬q -> ¬p : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p || q) != imp(!p, q)) ans = false;
        }
    cout << "p v q ≡ ¬p -> q : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p && q) != !(imp(p, !q))) ans = false;
        }
    cout << "p ^ q ≡ ¬(p -> ¬q) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((!imp(p, q)) != (p && !q)) ans = false;
        }
    cout << "¬(p -> q) ≡ p ^ ¬q : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((imp(p, q) && imp(p, r)) != imp(p, (q && r)))) ans = false;
            }
    cout << "(p->q) ^ (p->r) ≡ p->(q ^ r) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((imp(p, r) && imp(q, r)) != (imp((p || q), r)))) ans = false;
            }
    cout << "(p->r) ^ (q->r) ≡ (p v q)->r : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((imp(p, q) || imp(p, r)) != (imp(p, (q || r))))) ans = false;
            }
    cout << "(p->q) v (p->r) ≡ p->(q v r) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((imp(p, r) || imp(q, r)) != (imp((p && q), r)))) ans = false;
            }
    cout << "(p->r) v (q->r) ≡ (p ^ q)->r : " << (ans ? "Dung" : "Sai") << endl;


    // 8
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (iff(p, q) != (imp(p, q) && imp(q, p))) ans = false;
        }
    cout << "p <-> q ≡ (p->q) ^ (q->p) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (iff(p, q) != iff(!p, !q)) ans = false;
        }
    cout << "p <-> q ≡ ¬p <-> ¬q : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (iff(p, q) != ((p && q) || (!p && !q))) ans = false;
        }
    cout << "p <-> q ≡ (p ^ q) v (¬p ^ ¬q) : " << (ans ? "Dung" : "Sai") << endl;
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((!iff(p, q)) != (iff(p, !q))) ans = false;
        }
    cout << "¬(p <-> q) ≡ p <-> ¬q : " << (ans ? "Dung" : "Sai") << endl;


}