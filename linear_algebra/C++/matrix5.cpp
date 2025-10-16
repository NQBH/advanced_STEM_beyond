#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cout<<"nhap hang vaf cot:";
    cin>>m>>n;
    
    double A[m][n];
    cout<<"nhap ma tran A:";
    for(int i = 0; i < m ; i++) 
        for ( int j = 0; j<n;j++)
        cin>> A[i][j];
    double T[m][n];
    for(int i = 0;i<m;i++)
        for(int j= 0;j<n;j++)
        T[i][j] = A[i][j];

    cout<<"ma tran chuyen vi cua a la:\n";
    for(int i=0;i<m;i++) {
        for(int j =0;j<n;j++){
            cout<<T[j][i] <<" ";
        }
        cout << endl;
    }return 0;
}