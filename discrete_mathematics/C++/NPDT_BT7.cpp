#include <iostream>
using namespace std;

int main() {
    bool p, q, r, s;
    bool ans = 0;
// Problem 65a:
    cout << "65a : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            if (((p || !q) && (!p || q) && (!p || !q)) == true) {
                ans = 1;
                cout << "satisfiable " << p << " " << q << endl << '\n';
                
            } 
        }        
    if ( ans == 0){
        cout << "unsatisfiable\n" << endl;
         
    }  

// Problem 65b:
    cout << "65b : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            if (((!p || q) && (!p || !q) && (p || q) && (p || !q)) == true) {
                ans = 1; 
                cout << "satisfiable " << p << " " << q << endl << '\n';
                return 0;
            
            }
        }    
    if ( ans == 0){
        cout << "unsatisfiable\n" << endl;
        
    } 
// Problem 65c:
    cout << "65c : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            if (((p == q) && (!p == q)) == true) {
                ans = 1; 
                cout << "satisfiable " << p << " " << q << endl << '\n';
                return 0;            
            }
        }    
    if ( ans == 0){
        cout << "unsatisfiable\n" << endl;
        
    }   

// Problem 66a:
    cout << "66a : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            for (int k = 0; k < 2; ++k) {
                r = i;
                for (int l = 0; l < 2; ++l)
                    s = l;
                if (((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) == true) {
                ans = 1; 
                cout << "satisfiable " << p << " " << q << "  " << r << "  " << s << endl << '\n';
                return 0; 
                }
            }
        }        
    if ( ans == 0)
        cout << "unsatisfiable\n" << endl;
   
// Problem 66b:
    cout << "66b : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            for (int k = 0; k < 2; ++k) {
                r = i;
                for (int l = 0; l < 2; ++l)
                    s = l;
                if (((!p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && ( p || !r || !s)) == true) {
                ans = 1; 
                cout << "satisfiable " << p << " " << q << "  " << r << "  " << s << endl << '\n';
                return 0; 
                }
            }
        }        
    if ( ans == 0)
        cout << "unsatisfiable\n" << endl;     

// Problem 66c:
    cout << "66c : ";
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) 
            q = j;
            for (int k = 0; k < 2; ++k) {
                r = i;
                for (int l = 0; l < 2; ++l)
                    s = l;
                if (((p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s)) == true) {
                ans = 1; 
                cout << "satisfiable " << p << " " << q << "  " << r << "  " << s << endl << '\n';
                return 0; 
                }
            }
        }        
    if ( ans == 0)
        cout << "unsatisfiable\n" << endl;     

}
            
       


