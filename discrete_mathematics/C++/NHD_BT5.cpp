#include <iostream>
using namespace std;

int main() {
     bool p, q, r, p_imply_q;

     for (int i = 0; i <= 1; ++i) {
          for (int j = 0; j <= 1; ++j) {
               p = i;
               q = j;
               r = false; // Hoặc bạn có thể lặp thêm r nếu muốn kiểm tra thêm

               // p -> q là false chỉ khi p = true và q = false
               if (p == true && q == false)
                    p_imply_q = false;
               else
                    p_imply_q = true;

               cout << "p: " << p << ", q: " << q << endl;

               // Bảng so sánh tương đương logic
               cout << "p_imply_q <=> (!p || q): " << (p_imply_q == (!p || q)) << endl;
               cout << "p -> q <=> _p or q: " << (p_imply_q == (!p || q)) << endl;
               cout << "p -> q <=> _q -> _p: " << (p_imply_q == ((!q) || (!p))) << endl;
               cout << "p or q <=> _p -> q: " << ((p || q) == (!p || q)) << endl;
               cout << "p and q <=> (p -> q): " << ((p && q) == (p ? q : true)) << endl;
               cout << "¬(p -> q) <=> p and ¬q: " << ((!p_imply_q) == (p && !q)) << endl;

               // Thêm kiểm tra với r = false (hoặc có thể lặp như p, q)
               cout << "(p -> q) and (p -> r) <=> p -> (q and r): "
                    << ((p_imply_q && (p ? r : true)) == (p ? (q && r) : true)) << endl;

               cout << "(p -> r) and (q -> r) <=> (p or q) -> r: "
                    << (((p ? r : true) && (q ? r : true)) == ((p || q) ? r : true)) << endl;

               cout << "(p -> q) or (p -> r) <=> p -> (q or r): "
                    << ((p_imply_q || (p ? r : true)) == (p ? (q || r) : true)) << endl;

               // Các biểu thức liên quan đến tương đương "<->"
               cout << "p <-> q <=> (p -> q) and (q -> p): "
                    << ((p == q) == ((p ? q : true) && (q ? p : true))) << endl;

               cout << "p <-> q <=> _p <-> _q: "
                    << ((p == q) == ((!p == !q))) << endl;

               cout << "p <-> q <=> (p and q) or (_p and _q): "
                    << ((p == q) == ((p && q) || (!p && !q))) << endl;

               cout << "_p <-> q <=> _ (p <-> _q): "
                    << ((!p == q) == !(p == !q)) << endl;

               cout << "------------------------------" << endl;
          }
     }

     return 0;
}
