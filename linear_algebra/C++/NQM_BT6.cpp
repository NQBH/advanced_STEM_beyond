#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cout << "Nhap so hang va cot A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double> (n));
    cout << "Nhap vector A: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        
    }

    vector<double> b(m);
    cout << "Nhap vector b co " << m << " phan tu: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    if ((int)b.size() != m)
    {
        cout << "Impossible\n";
    } else {
        cout << "Ma tran bo sung [A|B]: \n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << b[i] << endl;
        }
        
    }
    
    
}