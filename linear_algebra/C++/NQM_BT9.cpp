#include <iostream>
#include <vector>
using namespace std;

bool mt_vuong(int m, int n) {
    return m == n;
}

bool mt_cheo(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && A[i][j] != 0)
            {
                return false;
            }

        }

    }
    return true;


}
bool tamgiac_tren(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i][j] != 0)
            {
                return false;
            }

        }

    }
    return true;

}

bool tamgiac_duoi(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                return false;
            }

        }

    }
    return true;

}

bool mt_doixung(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                return false;
            }

        }

    }
    return true;

}

int main() {
    int m, n;
    cout << "Nhap so hang m va so cot n: ";
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));
    cout << "Nhap ma tran A: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }

    }

    if (!mt_vuong(m, n))
    {
        cout << "Ma tran khong vuong" << endl;
        return 0;
    }


    if (mt_cheo(A))
    {
        cout << "La ma tran duong cheo" << endl;
    } else {
        cout << "Khong la ma tran duong cheo" << endl;
    }

    if (tamgiac_tren(A))
    {
        cout << "La ma tran tam giac tren" << endl;
    } else {
        cout << "Khong la ma tran tam giac tren" << endl;
    }

    if (tamgiac_duoi(A))
    {
        cout << "La ma tran tam giac duoi" << endl;
    } else {
        cout << "Khong la ma tran tam giac duoi" << endl;
    }

    if (mt_doixung(A))
    {
        cout << "La ma tran doi xung (A= A^T)" << endl;
    } else {
        cout << "Khong la ma tran doi xung" << endl;
    }

    return 0;
}
