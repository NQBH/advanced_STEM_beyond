#include <iostream>
using namespace std;
int main (){
    int n;
    int chẳn = 0, lẻ = 0;
    cout << "nhap vao n so nguyen: " << endl;
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (x % 2 == 0){
            chẳn = chẳn + 1;
        }else{
            lẻ = lẻ + 1;
        }

    }
    cout << "so chan: " << chẳn << endl;
    cout << "so le: " << lẻ << endl;
}