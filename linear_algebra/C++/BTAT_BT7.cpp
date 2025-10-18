#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va so cot cua ma tran A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Chon phep bien doi:\n";
    cout << "1. Doi cho hai hang\n";
    cout << "2. Nhan 1 hang voi hang so alpha\n";
    cout << "3. Cong alpha lan hang i vao hang j\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int r1, r2;
        cout << "Nhap hai hang muon doi: ";
        cin >> r1 >> r2;
        swap(A[r1], A[r2]);
    } 
    else if (choice == 2) {
        int r;
        double alpha;
        cout << "Nhap hang va alpha: ";
        cin >> r >> alpha;
        for (int j = 0; j < n; ++j)
            A[r][j] *= alpha;
    } 
    else if (choice == 3) {
        int i, j;
        double alpha;
        cout << "Nhap i, j, alpha (hang j = hang j + alpha * hang i): ";
        cin >> i >> j >> alpha;
        for (int k = 0; k < n; ++k)
            A[j][k] += alpha * A[i][k];
    } 
    else {
        cout << "Lua chon khong hop le!\n";
        return 0;
    }

    cout << "Ma tran sau bien doi:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
