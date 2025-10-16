#include <iostream>
using namespace std;

int main () {
// bang 7
//cau 1
    bool p, q, n, ans = true; 
    for (int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
        p = i, q = j;
        if ( p == true && q == false ) n = false;

        else n = true;

        if ((!p && q) && n == false)
            ans = false;
    cout << "p -> q <=> !p or q " << ans << '\n';
    

// cau 2
    bool n1, ans1 = true;

    for (int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
        p = i, q = j;
        if ( p == true && q == false ) n = false;

        else n = true;
        
        if ((!q == true) && (!p == false)) n1 = false;
        
        else n1 = true;

        if ( n != n1 ) ans = false ;
        cout <<"p -> q <=> !q -> !p " << ans1 << '\n';


//cau 3
    bool n2, ans2 = true;

     for (int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
        p = i, q = j;
        if ( !p == true && q == false ) n2 = false;

        else n2 = true;

        if (( p || q ) != n2 ) ans2 = false ;
        cout <<"p or q <=> !p -> q " << ans2 << '\n';


//cau 4
    bool n3, ans3 = true;

     for (int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
        p = i, q = j;
        if ( p == true && !q == false ) n3 = false;

        else n3 = true;

        if (( p && q ) != !n3 ) ans3 = false ;

        cout << "p and q <=> !(p && !q )  "<< ans3 << '\n' ;


// cau 5 
    bool n4, ans4 = true;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0 ; j <= 1; ++j)
        p = i, q = j ;
        if ( p == true && q == false) n4 = false;
        
        else n4 = true;

        if ((p && !q) && !n4 == false)
            ans4 = false;
        cout << "!( p -> q ) <=> p and !q  " << ans4 << '\n' ;
        
        
//cau 6 
    bool r, n5,n6,n7, ans5 = true;
    
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k)
        p = i, q = j, r = k;   

        if (p == true && q == false) 
            n5 = false;
        else 
            n5 = true;

        if (p == true && r == false) 
            n6 = false;
        else 
            n6 = true;

        if (p == true && (q && r)== false) 
            n7 = false;
        else 
            n7 = true;

        if ((n5 && n6) && n7 == false) 
            
            ans5 = false;
        cout <<"(p -> q) && (p -> r) <=> p -> (q && r)  "<< ans5 << '\n';


//cau 7
    bool n8,n9,n10,ans6 = true;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k)
        p = i, q = j, r = k;   

        if (p == true && r == false) 
            n8 = false;
        else 
            n8 = true;

        if (q == true && r == false) 
            n9 = false;
        else 
            n9 = true;

        if ((p || q) == true && r == false) 
            n10 = false;
        else 
            n10 = true;

        if ((n8 && n9) && n10 == false) 
             ans6 = false;
        cout << "(p -> r) && (q -> r) <=> (p || q) -> r "<< ans6 << '\n';
        
        
// cau 8
    bool n11,n12,n13, ans7= true;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k)
        p = i, q = j, r = k;   

        if (p == true && q == false) 
            n11 = false;
        else 
            n11 = true;

        if (p == true && r == false) 
            n12 = false;
        else 
            n12 = true;

        if (p == true && (q || r)== false) 
            n13 = false;
        else 
            n13 = true;

        if ((n11 || n12) && n13 == false) 
             ans7 = false;
        cout << "(p -> q) or (p -> r) <=>  p -> (q or r) "<< ans7 << '\n';


//cau 9 
    bool n14,n15,n16, ans8 = true; 

         for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k)
        p = i, q = j, r = k;   

        if (p == true && r == false) 
            n14 = false;
        else 
            n14 = true;

        if (q == true && r == false) 
            n15 = false;
        else 
            n15 = true;

        if ((p && q) == true && r == false) 
            n16 = false;
        else 
            n16 = true;

        if ((n14 || n15) && n16 == false)
            ans8= false;
        cout << "(p -> r) or (q -> r) <=> (p and q) -> r "<< ans8 <<'\n';


//----------------------------------------------------------

//Bang 8
//cau1
    bool n17,n18,n19, ans9 = true;
    for (int i = 0; i <= 1; ++i )
        for (int j = 0; j <= 1; ++j )
    p = i, q = j;

    if ((p == true && q == false) or (p == false && q == true)) 
        n17 = false;
    else 
        n17 = true; 

    if (p== true && q == false) 
        n18 = false;
    else
        n18 = true;
    
    if (q == true && p == false)
        n19 = false;
    else 
        n19 = true;

    if (n17 && (n18 && n19) == false) 
        ans9 = false;
    cout << "(p <=> q) <=> (p -> q) && (q -> p) "<< ans9 << '\n' ;


// cau 2
    bool n20, n21, ans10 = true;
    for (int i = 0; i <= 1; ++i )
        for (int j = 0; j <= 1; ++j )
    p = i, q = j;

         if ((p == true && q == false) or (p == false && q == true)) 
        n20 = false;
    else 
        n20 = true; 
         if ((!p == true && !q == false) or (!p == false && !q == true)) 
        n21 = false;
    else 
        n21 = true; 
    if (n20 && n21 == false)
        ans10 = false;
    cout << "(p <=> q) <=> (!p <=> !q) " << ans10 << '\n';


//cau 3
    bool n22, ans11 = true; 
     for (int i = 0; i <= 1; ++i )
        for (int j = 0; j <= 1; ++j )
    p = i, q = j;
         if ((p == true && q == false) or (p == false && q == true)) 
        n22 = false;
    else 
        n22 = true; 
        if (n22 && ((p && q) || (!p && !q)) == false)
            ans11 = false;
        cout <<"(p <=> q) <=> (p and q) || (!p and !q)  "<< ans11 << '\n';


// cau 4
    bool n23,n24, ans12 = true;
     for (int i = 0; i <= 1; ++i )
        for (int j = 0; j <= 1; ++j )
    p = i, q = j;
         if ((p == true && q == false) or (p == false && q == true)) 
        n23 = false;
    else 
        n23 = true; 
         if ((p == true && !q == false) or (p == false && !q == true)) 
        n24 = false;
    else 
        n24 = true; 
        if (!n23 && n24 == false)
            ans12 = false;
        cout << "(!(p <=> q)) <=> (p <=> !q) " << ans12 << '\n';

}