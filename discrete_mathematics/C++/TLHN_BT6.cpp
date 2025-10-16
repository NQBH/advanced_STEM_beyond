#include <iostream>
using namespace std;

int main() {
    bool p, q, r;   // Các biến logic p, q, r (có giá trị true hoặc false)
    bool ans;        // Biến kiểm tra kết quả



    // TABLE 7


    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((!p || q) != (!p || q)) ans = false;
        }
    cout << "p -> q tương đương voi khong p hoac q: " << ans << endl;
    //         if ((!p || q) != (!p || q)) ans=false;
    //    cout << "p -> q ~ not p or q is " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((!p || q) != (q || !p)) ans = false;
        }
    cout << "p -> q tuong duong voi khong q -> khong p: " << ans << endl;

//         if ((!p || q) != (q || !p)) ans=false;
//        cout << "p -> q ~ not q -> not p is  " <<ans <<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p || q) != (q || p)) ans = false;
        }
    cout << "p hoac q tuong duong voi q hoac p: " << ans << endl;
//        if ((p || q) != (!p || q)) ans=false;
//        cout << "p or q ~ not q -> p is  " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p && q) != (!(!p || !q))) ans = false;
        }
    cout << "p va q tuong duong voi khong (p -> khong q): " << ans << endl;

//         if ((p && q) != (!(!p || !q))) ans=false;
//        cout << "p and q ~ not (p -> not q) is  " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((!(!p || q)) != (p && !q)) ans = false;
        }
    cout << "khong (p -> q) tuong duong voi p va khong q: " << ans << endl;

//         if ((!(!p || q)) != (p && !q)) ans=false;
//        cout << "not (p -> q) ~ p and not q is  " <<ans <<endl;



    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
            }
    cout << "(p -> q) va (p -> r) tuong duong voi p -> (q va r): " << ans << endl;


//            for (int r=0; r<=1; ++r)
//            if (((!p || q) && (!p || r))!= (!p ||(q && r))) ans=false;
//            cout << "(p -> q) and ( p -> r) ~ p -> (q and r) is  " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                if (((!p || r) && (!q || r)) != ((! (p || q)) || r)) ans = false;
            }
    cout << "(p -> r) va (q -> r) tuong duong voi (p hoac q) -> r: " << ans << endl;

//             if (((!p || r) && (!q || r))!= (!(p || q)) || r) ans=false;
//            cout << "(p -> r) and ( q -> r) ~ (p or q) -> r is  " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
            }
    cout << "(p -> q) hoac (p -> r) tuong duong voi p -> (q hoac r): " << ans << endl;


//             if (((!p || q) || (!p || r))!= (!p ||(q || r))) ans=false;
//            cout << "(p -> q) or ( p -> r) ~ p -> (q or r) is  " <<ans<<endl;




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                if (((!p || r) || (!q || r)) != ((! (p && q)) || r)) ans = false;
            }
    cout << "(p -> r) hoac (q -> r) tuong duong voi (p va q) -> r: " << ans << endl;


//            if (((!p || r) || (!q || r))!= (!(p && q)) || r) ans=false;
//            cout << "(p -> r) or ( q -> r) ~ (p and q) -> r is  " <<ans<<endl;









    // TABLE 8




    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p == q) != ((!p || q) && (!q || p))) ans = false;
        }
    cout << "p <-> q tuong duong voi (p -> q) va (q -> p): " << ans << endl;

//             if ((p == q) != (!p || q) && (!q || p)) ans=false;
//            cout << "p <-> q ~ (p -> q) and (q -> p) is " <<ans<<endl;





    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p == q) != (!p == !q)) ans = false;
        }
    cout << "p <-> q tuong duong voi (khong p <-> khong q): " << ans << endl;



//             if ((p == q) != (!p == !q)) ans=false;
//            cout << "p <-> q ~ (not p <-> not q) is " <<ans<<endl;





    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p == q) != ((p && q) || (!p && !q))) ans = false;
        }
    cout << "p <-> q tuong duong voi (p va q) hoac (khong p va khong q): " << ans << endl;



//            if ((p == q) != (p && q) || (!p && !q)) ans=false;
//            cout << "p <-> q ~ (p and q) or (!p and not q) is " <<ans<<endl;





    ans = true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((! (p == q)) != (p == !q)) ans = false;
        }
    cout << "khong (p <-> q) tuong duong voi p <-> khong q: " << ans << endl;



//             if ((!(p == q)) != (p == !q)) ans=false;
//            cout << "not (p <-> q) ~ p <-> not q is " <<ans<<endl;





    return 0;
}
