// ex2
#include <iostream>
using namespace std;

int main(){
    int p,q;
    cout << "P: " << endl;
    cin >> p;
    cout << "Q: " << endl;
    cin >> q;
    
    bool bp = (p!=0);
    bool bq = (q!=0);
    
    cout << "p & q" << (bp && bq) << endl;
    cout << "p or q" << (bp || bq) << endl;
    cout << "not p" << (!bp) << endl;
    cout << "not q" << (!bq) << enndl;
    cout << "p ^ q" << (bp ^ bq) << endl;
    
    return 0;
}