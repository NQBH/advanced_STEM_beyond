#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cout << "Nhap so hang va so cot cua ma tran A: ";
    if(!(cin >> m >> n)) return 0;
    vector<vector<int>> A(m, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran A (nhap tung hang):\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    int p;
    cout << "Nhap so phan tu cua vector b: ";
    cin >> p;
    vector<int> b(p);
    cout << "Nhap cac phan tu cua b:\n";
    for(int i = 0; i < p; i++){
        cin >> b[i];
    }
    if(p != m){
        cout << "Impossible\n";
        return 0;
    }
    cout << "Ma tran bo sung [A|b]:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << b[i] << "\n";
    }
    return 0;
}