#include <iostream>
using namespace std;

int main() {

    bool p, q, r, s, cau_65a = false, cau_65b = false, cau_65c = false;

    bool       cau_66a = false, cau_66b = false, cau_66c = false;

    bool x = ( p || q || !r), x1 = (p || !q || !s), x2 = (!p || !r || !s),

         x3 = ( !p || !q || !s), x4 = (p || q || !s);

    bool m = (!p || !q || r), m1 = (!p || q || !s), m2 = (p || !q || !s),

         m3 = (!p || !r || !s), m4 = (p || q || !r), m5 = (q || !r || !s);

    bool n = (p || q || r), n1 = ( p || !q || !s), n2 = (q || !r || s),

         n3 = (!p || r || s), n4 = (!p || q || !s), n5 = (p || !q || !r),

         n6 = (!p || !q || s), n7 = (!p || !r || !s) ;
    for ( int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
            for ( int k = 0; k <= 1; ++k )
                for ( int l = 0; l <= 1; ++l )

                    p = i, q = j, r = k, s = l;

    if ( (p || ( !q )) &&  (!p || q) && (!p || !q) == true ) // cau 65a
        cau_65a = true;

    if ( ( !p || q) && (!p || !q ) && (p || q) && (p || !q) == true ) // cau 65b
        cau_65b = true ;

    if ( ((p && q ) || (!p && !q) && ((!p && q) || (p && !q)) ) == true) // cau 65c
        cau_65c = true ;

    if ( (x && x1 && x2 && x3 && x4) == true ) // cau 66a
        cau_66a = true;

    if ( (m && m1 && m2 && m3 && m4 && m5) == true ) // cau 66b
        cau_66b = true;

    if ( (n && n1 && n2 && n3 && n4 && n5 && n6 && n7) == true ) // cau 66c
        cau_66c = true;

    if (cau_65a == false)
        cout << " 65a is not satisfiable" << '\n';

    else
        cout << " 65a is satisfiable" << " " << p << "  " << q <<  '\n';

    if (cau_65b == false)
        cout << " 65b is not satisfiable" << '\n';

    else
        cout << " 65b is satisfiable" << " " << p << "  " << q <<  '\n';

    if (cau_65c == false)
        cout << " 65c is not satisfiable" << '\n';

    else
        cout << " 65c is satisfiable" << " " << p << " " << q << '\n';

    if (cau_66a == false)
        cout << " 66a is not satisfiable" <<  '\n';

    else
        cout << " 66a is satisfiable" << " " << p << " " << q << " " << r << " " << s << '\n';

    if (cau_66b == false)
        cout << " 66b is not satisfiable" << '\n';

    else
        cout << " 66b is satisfiable" << " " << p << " " << q << " " << r << " " << s << '\n';

    if (cau_66c == false)
        cout << " 66c is not satisfiable" <<  '\n';

    else
        cout << " 66c is satisfiable" << " " << p << " " << q << " " << r << " " << s << '\n';






}

