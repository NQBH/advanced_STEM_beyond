#include <iostream>
using namespace std;

int main() 
{
    int row, colum;
    int A[10][10], b[10];

    cout<< "Nhap so hang: ";
    cin>> row;
    cout<< "Nhap so cot: ";
    cin>> colum;
    
    cout << "Nhap ma tran ";
    for (int i=0; i<row; i++) {
        for (int j=0; j<colum; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    int sz_b;
    cout<< "Nhap so phan tu cua vector b: ";
    cin>> sz_b;
    cout<< "Nhap vector ";
    for (int i = 0; i < sz_b; i++) {
        cout<< "b[" << i << "] = ";
        cin>> b[i];
    }
    if (row != sz_b){
        cout<<"Impossible";
    }
    else{
        cout<<"[A|b]= "<<endl;
        for (int i=0; i<row; i++){
            for (int j=0; j<colum; j++){
                cout<< A[i][j] << " ";
            }
            cout<< "| " << b[i] << endl;
        }
    }
    

    return 0;
}