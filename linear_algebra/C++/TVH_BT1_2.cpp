#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
}


void hoan_doi_hang(vector<vector<int>>& matrix, int m, int n) {
    int a, b; cout << "Doi hang ... voi hang ...:"; cin >> a >> b;
    if (a - 1 > m || b - 1 > m) {cout << "Hang khong ton tai!"; return;}
    for (int i = 0; i < n; i++) {
        swap(matrix[a - 1][i], matrix[b - 1][i]);
    }
}
void nhan_he_so(vector<vector<int>>& matrix, int m, int n) {
    int a, b; cout << "Nhan hang ... voi ...(khac 0) "; cin >> a >> b;
    if (b == 0) return;
    for (int i = 0; i < n; i++) {
        matrix[a - 1][i] *= b;
    }
}
void cong_voi_boi_cua_hang_khac(vector<vector<int>>& matrix, int m, int n) {
    int a, b, c; cout << "Nhan hang ... voi ... lan cua hang ...: "; cin >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        matrix[a - 1][i] += matrix[c - 1][i] * b;
    }
}

void print(vector<vector<int>> matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void BDSC(vector<vector<int>>& matrix, int m, int n) {
    int choose;
    while (true) {
        cout << "1. Hoan doi hang\n";
        cout << "2. Nhan he so khac 0\n";
        cout << "3. Cong hang nay voi mot boi cua hang khac\n";
        cout << "4. In ma tran hien tai\n";
        cout << "5: Thoat\n";
        cout << "Chon: ";
        cin >> choose;
        switch (choose) {
        case 1: {hoan_doi_hang(matrix, m, n); break;}
        case 2: {nhan_he_so(matrix, m, n); break;}
        case 3: {cong_voi_boi_cua_hang_khac(matrix, m, n); break;}
        case 4: {print(matrix, m, n); break;}
        case 5: return;
        default: {
            break;
        }
        }
    }
}

void cau_1() {
    int m, n; cout << "Nhap m va n cua ma tran A:"; cin >> m >> n;
    int M; cout << "Nhap so phan tu trong vec to B:"; cin >> M;
    if (m != M) {
        cout << "Impossible!"; return;
    }
    vector<vector<int>> matrix(m, vector<int> (n));
    cout << "Nhap ma tran A: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> matrix_2(M);
    cout << "Nhap vector B: " << endl;
    for (int i = 0; i < M; i++) {
        cin >> matrix_2[i];
    }
    vector<vector<int>> C(m, vector<int> (n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j < n) C[i][j] = matrix[i][j];
            else C[i][j] = matrix_2[i];
        }
    }
    cout << "Ma tran bo sung [A|B] la: " << endl;
    print(C, m, n + 1);
    return;
}
int main() {
    int choose;
    while (true) {
        cout << "1. Cau 1\n";
        cout << "2. Cau 2\n";
        cout << "3. Thoat\n";
        cout << "Nhap: ";
        cin >> choose;
        switch (choose) {
        case 1: {cau_1(); break;}
        case 2: {
            int m, n; cout << "Nhap kich thuoc ma tran :"; cin >> m >> n;
            vector<vector<int>> mat(m, vector<int> (n));
            cout << "Nhap ma tran: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> mat[i][j];
                }
            }
            BDSC(mat, m, n);
            break;
        }
        case 3: return 0;
        default: break;
        }
    }
    return 0;
}
