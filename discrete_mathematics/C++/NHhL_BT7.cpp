#include <iostream>
using namespace std;

int main() {
    bool is_satisfiable;

     cout << " --- bảng 65a ---\n";
     //a.(p V !q) ^ (!p v q) ^ (!p v !q)
     is_satisfiable = false; 
	 for (int p = 0; p <= 1; ++p) {
		for (int q = 0; q <= 1; ++q) {
			if ((p || !q) && (!p || q) && (!p || !q)) {
			   is_satisfiable = true;
			   cout << "satisfiable p=" << p << ", q=" << q << "\n";
			}
        }
     }
	 if (is_satisfiable == false) cout << "unsatisfiable\n";

      //b.(p -> q) ^ (p -> !q) ^ (!p -> q) ^ (!p -> !q)
     cout << " --- bảng 65b ---\n";
     is_satisfiable = false; 
	 for (int p = 0; p <= 1; ++p) {
		for (int q = 0; q <= 1; ++q) {
			  if ((!p || q) && (!p || !q) && (!(!p || q) && (!(!p || !q)))) {
			    is_satisfiable = true;
			     cout << "satisfiable p=" << p << ", q=" << q << "\n";			
			}
        }
     }
	 if (is_satisfiable == false) cout << "unsatisfiable\n";

     //c.(p <-> q) ^ (!p <-> q)
     cout << " --- bảng 65c ---\n";
     is_satisfiable = false; 
	 for (int p = 0; p <= 1; ++p) {
		for (int q = 0; q <= 1; ++q) {
			if ((p == q) && (!p == q)) {
			    is_satisfiable = true;
			    cout << "satisfiable p=" << p << ", q=" << q << "\n";				
			}
        }
     }
	 if (is_satisfiable == false) cout << "unsatisfiable\n";

     cout << " ----------------\n";

     
    //a.(p v q v !r) ^ (p v !q v !r) ^ (p v !r v !s) ^ (!p v !q v !s) ^ (p v q v !s)
    cout << " --- bảng 66a ---\n";
    is_satisfiable = false; 
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                for (int s = 0; s <= 1; ++s) {
                    if ((p || q || !r) && (p || !q || !r) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
                        if (p == 0 && q == 1 && r == 0 && s == 0) {
                            is_satisfiable = true;
                            cout << "satisfiable p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n"; 
                        }
                    } 
                } 
            }
        }
    }
    if (is_satisfiable == false) cout << "unsatisfiable\n";

     //b.(!p v !q v r) ^ (!p v q v !s ) ^ (p v !q v !s) ^ (!p v !r v !s) ^ (p v q v !r) ^ (p v !r v !s)
    cout << " --- bảng 66b ---\n";
    is_satisfiable = false; 
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                for (int s = 0; s <= 1; ++s) {
                    if ((!p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && (p || !r || !s)) {
                        if (p == 1 && q == 0 && r == 0 && s == 0) {
                            is_satisfiable = true;
                            cout << "satisfiable p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n"; 
                        }
                    } 
                } 
            }
        }
    }
    if (is_satisfiable == false) cout << "unsatisfiable\n";

    //c. (p v q v r) ^ (p v !q v !s) ^ (q v !r v s) ^ (!p v r v s) ^ (!p v q v !s) ^ (p v !q v !r) ^ (!p v !q v s) ^ (!p v !r v !s)
    cout << " --- Bảng 66c ---\n";
    is_satisfiable = false; 
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                for (int s = 0; s <= 1; ++s) {
                    if ((p || q ||r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s)) {
                        if (p == 0 && q == 1 && r == 0 && s == 0) {
                            is_satisfiable = true;
                            cout << "satisfiable p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n"; 
                        }
                    } 
                } 
            }
        }
    }
    if (is_satisfiable == false) cout << "unsatisfiable\n";

    return 0;
}

