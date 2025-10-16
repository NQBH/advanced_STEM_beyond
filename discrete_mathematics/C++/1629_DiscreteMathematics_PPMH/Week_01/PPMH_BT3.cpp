#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;
    
    bool P = (x+1 == 2);
    bool Q = (x+y == z);
    
    cout << "P: x+1=2 =>" << (P ? "Dung" : "Sai") << endl;
    cout << "Q: x+y=z =>" << (Q ? "Dung" : "Sai") << endl;
    
    bool original = (!P) || Q;
    cout << "Menh de goc (P => Q): " << (original ? "Dung" : "Sai") << endl;
    
    bool converse = (!Q) || P;
    cout << "Dao (Q => P): " << (converse ? "Dung" : "Sai") << endl;
    
    // Phan dao ~P => ~Q
    bool inverse = (P) || (!Q);
    cout << "Phan dao ~P => ~Q:" << (inverse ? "Dung" : "Sai") << endl;
    
    // Nghich dao
    bool contrapositive = (Q) || (!P);
    cout << "Nghich dao ~Q => ~P:" << (contrapositive ? "Dung" : "Sai") << endl;
    
    return 0;
}