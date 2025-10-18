#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void cau_1()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    cout << "Ma tra 0 kich thuoc " << n << "x" << n << " la:\n";
    print_matrix(matrix, n, n);
    cout << "Ma tra don vi kich thuoc " << n << "x" << n << " la:\n";
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 1;
    }
    print_matrix(matrix, n, n);
}
bool matran_duong_cheo(vector<vector<int>> matrix, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
bool ma_tran_tam_giac_duoi(vector<vector<int>> matrix, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
bool matran_tam_giac_tren(vector<vector<int>> matrix, int m, int n)
{
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
bool matran_doi_xung(vector<vector<int>> matrix, int m, int n)
{
    vector<vector<int>> matrix_2(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix_2[i][j] = matrix[j][i];
        }
    }
    if (matrix_2 == matrix)
        return true;
    return false;
}
void cau_9()
{
    int m, n;
    cout << "Nhap kich thuoc: ";
    cin >> m >> n;
    if (m != n)
    {
        cout << "Ma tran thuong!\n";
        return;
    }
    else
    {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        vector<bool> arr = {matran_duong_cheo(matrix, m, m), matran_tam_giac_tren(matrix, m, n), ma_tran_tam_giac_duoi(matrix, m, n), matran_doi_xung(matrix, m, n)};
        vector<string> inf = {"Ma tran duong cheo!\n", "Ma tran tam giac tren!\n", "Ma tran tam giac duoi!\n", "Ma tran doi xung!\n"};
        for (int i = 0; i < 4; i++)
        {
            if (arr[i])
                cout << inf[i];
        }
    }
}
void cau_10()
{
    vector<vector<float>> matrix(2, vector<float>(2));
    cout << "Nhap ma tran kich thuoc 2x2: \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> matrix[i][j];
        }
    }
    float detA = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    cout << "Dinh thuc cua ma tran la " << detA;
}
int main()
{
    cau_1();
    cau_9();
    cau_10();
    return 0;
}