#include <iostream>

using namespace std;

int main() {
    bool p, q, r;
    bool ans; // lưu kết quả

    cout << "---Bảng 7 (2 biến ) ---\n";
    // 1. p -> q <=> !p || q
    ans = true; 
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if ( (!p || q) != (!p || q) ) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 1. p -> q <=> !p || q: " << (ans ? "True" : "False") << "\n";

    // 2. p -> q <=> !q -> !p (Phản đảo)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if ( (!p || q) != (!!q || !p) ) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 2. p -> q <=> !q -> !p: " << (ans ? "True" : "False") << "\n";

      // 3. p v q <=> !p -> q (Phản đảo)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1); 
            q = (j == 1);
            if ( (p || q) != (!!q || p) ) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 3. p v q <=> !p -> q: " << (ans ? "True" : "False") << "\n";

    // 4. p ^ q <=> !(!p -> !q) (Phản đảo)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1); 
            q = (j == 1);
            if ( (p && q) != !(!p || !q) ) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 4. p ^ q <=> !(!p -> !q): " << (ans ? "True" : "False") << "\n";

    // 5. !(p -> q) <=> p ^ !q (Phản đảo)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1); 
            q = (j == 1);
            if ( (!(!p || q) != p && !q)) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 5. !(p -> q) <=> p ^ !q): " << (ans ? "True" : "False") << "\n";
    
    // ----------------------------------------------------------------------

    cout << "\n--- Bảng 7 (3 biến )---\n";

    // 6. (p -> q) ^ (p -> r) <=> p -> (q ^ r)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) { 
            for (int k = 0; k <= 1; ++k) {
                p = (i == 1);
                q = (j == 1);
                r = (k == 1);
                if ( ((!p || q) && (!p || r)) != (!p || (q && r)) ) { 
                    ans = false; break;
                }
            }
            if (!ans) break;
        }
        if (!ans) break;
    }
    cout << " 6. (p -> q) ^ (p -> r) <=> p -> (q ^ r): " << (ans ? "True" : "False") << "\n";
    
// 7. (p -> r) ^ (q -> r) <=> (p v q) -> r )
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) { 
            for (int k = 0; k <= 1; ++k) {
                p = (i == 1);
                q = (j == 1);
                r = (k == 1);
                if ( (!p || r) && (!q || r) != (!(p || q) || r)) { 
                    ans = false; break;
                }
            }
            if (!ans) break;
        }
        if (!ans) break;
    }
    cout << " 7. (p -> r) ^ (q -> r) <=> (p v q) -> r ): " << (ans ? "True" : "False") << "\n";
    
    // 8. (p -> q) v (p -> r) <=> p -> (q V r)
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) { 
            for (int k = 0; k <= 1; ++k) {
                p = (i == 1);
                q = (j == 1);
                r = (k == 1);
                if (((!p || q ) || (!p || r)) != (!p || (q || r))) { 
                    ans = false; break;
                }
            }
            if (!ans) break;
        }
        if (!ans) break;
    }
    cout << " 8. (p -> q) v (p -> r) <=> p -> (q V r) ): " << (ans ? "True" : "False") << "\n";
    
     // 9. (p -> r) v (q -> r) <=> (p ^ q) -> r
    ans = true; 
    for (int i = 0; i <= 1; ++i) { 
        for (int j = 0; j <= 1; ++j) { 
            for (int k = 0; k <= 1; ++k) {
                p = (i == 1);
                q = (j == 1);
                r = (k == 1);
                if (((!p || r) || (!q || r)) != (!(p && q) || r)) { 
                    ans = false; break;
                }
            }
            if (!ans) break;
        }
        if (!ans) break;
    }
    cout << " 9. (p -> r) v (q -> r) <=> (p ^ q) -> r: " << (ans ? "True" : "False") << "\n";
     
      cout << "---Bảng 8 ---\n";
    // 1. p <-> q <=> ( p-> q) ^ (q -> p)
    ans = true; 
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if ( (p == q) != ((!p || q) && (!q || p))) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 1. p <-> q <=> ( p-> q) ^ (q -> p): " << (ans ? "True" : "False") << "\n";
    
    // 2. p <-> q <=> !p <-> !q
    ans = true; 
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if ( (p == q ) != (!p == !q)) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 2. p <-> q <=> !p <-> !q: " << (ans ? "True" : "False") << "\n";
    
     // 3. p <-> q <=> (p ^ q) v (!p ^ !q)
    ans = true; 
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if ((p == q) != ((p && q) || (!p && !q))) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 3. p <-> q <=> (p ^ q) v (!p ^ !q): " << (ans ? "True" : "False") << "\n";
    
    // 4. !(p <-> q) <=> p <-> !q
    ans = true; 
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            p = (i == 1);
            q = (j == 1);
            if (!(p == q) != (p == !q)) { 
                ans = false; break;
            }
        }
        if (!ans) break;
    }
    cout << " 4. !(p <-> q) <=> p <-> !q: " << (ans ? "True" : "False") << "\n";
    return 0;
}