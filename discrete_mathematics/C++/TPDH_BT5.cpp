#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool ok; // biến kiểm tra kết quả
    cout << "=== KIEM TRA CAC LUAT LOGIC (TABLE 6 - ROSEN) ===\n\n";
    // 1. Identity laws
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ((p && true) != p) ok = false;
        if ((p || false) != p) ok = false;
    }
    cout << "1. Identity laws: " << (ok ? "Dung" : "Sai") << endl;
    // 2. Domination laws
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ((p || true) != true) ok = false;
        if ((p && false) != false) ok = false;
    }
    cout << "2. Domination laws: " << (ok ? "Dung" : "Sai") << endl;
    // 3. Idempotent laws
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ((p || p) != p) ok = false;
        if ((p && p) != p) ok = false;
    }
    cout << "3. Idempotent laws: " << (ok ? "Dung" : "Sai") << endl;
    // 4. Double negation law
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ((!(!p)) != p) ok = false;
    }
    cout << "4. Double negation law: " << (ok ? "Dung" : "Sai") << endl;
     // 5. Commutative laws
    ok = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if ((p || q) != (q || p)) ok = false;
            if ((p && q) != (q && p)) ok = false;
        }
    cout << "5. Commutative laws: " << (ok ? "Dung" : "Sai") << endl;
    // 6. Associative laws
    ok = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                if (((p || q) || r) != (p || (q || r))) ok = false;
                if (((p && q) && r) != (p && (q && r))) ok = false;
            }
    cout << "6. Associative laws: " << (ok ? "Dung" : "Sai") << endl;
    // 7. Distributive laws
    ok = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                if ((p || (q && r)) != ((p || q) && (p || r))) ok = false;
                if ((p && (q || r)) != ((p && q) || (p && r))) ok = false;
            }
    cout << "7. Distributive laws: " << (ok ? "Dung" : "Sai") << endl;

    // 8. De Morgan’s laws
    ok = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if (!(p && q) != ((!p) || (!q))) ok = false;
            if (!(p || q) != ((!p) && (!q))) ok = false;
        }
    cout << "8. De Morgan's laws: " << (ok ? "Dung" : "Sai") << endl;
    // 9. Absorption laws
    ok = true;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if ((p || (p && q)) != p) ok = false;
            if ((p && (p || q)) != p) ok = false;
        }
    cout << "9. Absorption laws: " << (ok ? "Dung" : "Sai") << endl;
    // 10. Negation laws
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ((p || !p) != true) ok = false;
        if ((p && !p) != false) ok = false;
    }
    cout << "10. Negation laws: " << (ok ? "Dung" : "Sai") << endl;
    cout << "\n==> KIEM TRA HOAN TAT <==\n";
    return 0;
}