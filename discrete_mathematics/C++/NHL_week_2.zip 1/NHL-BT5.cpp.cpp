/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()   {
    bool p, q, r;
    bool ans;

    // 1
    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p && true) != p) ans = false;
    }
    cout << "p ^ T = p : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p || false) != p) ans = false;
    }
    cout << "p v F = p : " << (ans ? "Dung" : "Sai") << endl;

    // 2
    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p || true) != true) ans = false;
    }
    cout << "p v T = T : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p && false) != false) ans = false;
    }
    cout << "p ^ F = F : " << (ans ? "Dung" : "Sai") << endl;

    // 3
    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p || p) != p) ans = false;
    }
    cout << "p v p = p : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((p && p) != p) ans = false;
    }
    cout << "p ^ p = p : " << (ans ? "Dung" : "Sai") << endl;

    // 4
    ans = true;
    for (int i = 0; i <= 1; i++) {
        p = i;
        if ((!(!p)) != p) ans = false;
    }
    cout << "¬(¬p) = p : " << (ans ? "Dung" : "Sai") << endl;

    // 5
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p || q) != (q || p)) ans = false;
        }
    cout << "p v q = q v p : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p && q) != (q && p)) ans = false;
        }
    cout << "p ^ q = q ^ p : " << (ans ? "Dung" : "Sai") << endl;

    // 6
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((p || q) || r) != (p || (q || r))) ans = false;
            }
    cout << "(p v q) v r = p v (q v r) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if (((p && q) && r) != (p && (q && r))) ans = false;
            }
    cout << "(p ^ q) ^ r = p ^ (q ^ r) : " << (ans ? "Dung" : "Sai") << endl;

    // 7
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if ((p || (q && r)) != ((p || q) && (p || r))) ans = false;  } 
                cout << "p v (q ^ r) = (p v q) ^ (p v r) : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++) {
                p = i; q = j; r = k;
                if ((p && (q || r)) != ((p && q) || (p && r))) ans = false;
            }
    cout << "p ^ (q v r) = (p ^ q) v (p ^ r) : " << (ans ? "Dung" : "Sai") << endl;
    
    // 8
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (!(p && q) != ((!p) || (!q))) ans = false;
        }
    cout << "¬(p ^ q) = ¬p v ¬q : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if (!(p || q) != ((!p) && (!q))) ans = false;
        }
    cout << "¬(p v q) = ¬p ^ ¬q : " << (ans ? "Dung" : "Sai") << endl;

    // 9
    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p || (p && q)) != p) ans = false;
        }
    cout << "p v (p ^ q) = p : " << (ans ? "Dung" : "Sai") << endl;

    ans = true;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            p = i; q = j;
            if ((p && (p || q)) != p) ans = false;
        }
    cout << "p ^ (p v q) = p : " << (ans ? "Dung" : "Sai") << endl;


    // 10
    ans = true;
    for (int i = 0; i <= 1; i++) {
    p = i;
    if ((p || !p) != true) ans = false;}
    cout << "p v ¬p = T : " << (ans ? "Dung" : "Sai") << endl;
    ans = true;
    for (int i = 0; i <= 1; i++) {
    p = i;
    if ((p && !p) != false) ans = false;
    }
    cout << "p ^ ¬p = F : " << (ans ? "Dung" : "Sai") << endl;
    
}