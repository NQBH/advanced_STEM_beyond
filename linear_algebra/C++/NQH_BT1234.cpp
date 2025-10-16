# BÀI 1:
def nhap_ma_tran(m,n):
    A = []
    for i in range(m):
        row = []
        for j in range(n):
            x = float(input(f"A[{i}][{j}] = "))
            row.append
        A.append(row)
    return A

def xuat_ma_tran(A):
    for row in A:
        for x in row:
            print(x, end= "")
        print()

def main():
    m = int(input("Nhap so hang m: "))
    n = int(input("Nhap so cot n: "))
    print("Nhap ma tran A:")
    A = nhap_ma_tran(m,n)
    print("Ma tran A vua nhap:")
    xuat_ma_tran(A)

if __name__ == "__main__":
    main()


# BÀI 2:
def cong_ma_tran(A.B):
    m = len(A)
    n = len(A[0])
    c = [[A[i][j] + B[i][j] for j in range(n)] for i in range(m)]
    return c
def tru_ma_tran(A,B):
    m = len(A)
    n = len(A[0])
    c = [[A[i][j] - B[i][j] for j in range(n)] for i in range(m)]
    return 
def main():
    m = int(input("Nhap so hang m: "))
    n = int(input("Nhap so cot n: "))
    print("Nhap ma tran A:")
    A = [list(map(float,input().split())) for _ in range(m)]
    print("Nhap ma tran B:")
    B = [list(map(float,input().split())) for _ in range(m)]
    print("A + B =")
    C = cong_ma_tran(A,B)
    for row in C:
        print(*row)
    print("A - B =")
    D = tru_ma_tran(A,B)
    for row in D:
        print(*row)

if __name__ == "__main__":
    main()

# BÀI 3:
def nhan_vo_huong(A,c):
    m = len(A)
    n = len(A[0])
    C = [[A[i][j] * c for j in range(n)] for i in range(m)]
    return C

def main():
    m = int(input("Nhap so hang m: "))
    n = int(input("Nhap so cot n: "))
    print("Nhap ma tran A:")
    A = [list(map(float, input().split())) for _ in range(m)]
    c = float(input("Nhap so thuc c: "))
    C = nhan_vo_huong(A, c)
    print("c * A =")
    for row in C:
        print(*row)

if __name__ == "__main__":
    main()

# BÀI 4:
def nhan_ma_tran(A, B):
    m = len(A)
    n = len(A[0])
    p = len(B[0])
    c = [[0 for _ in range(p)] for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

def main():
    m = int(input("Nhap so hang A: "))
    n = int(input("Nhap so cot A (dong B): "))
    p = int(input("Nhap so cot B: "))
    print("Nhap ma tran A:")
    A = [list(map(float, input().split())) for _ in range(m)]
    print("Nhap ma tran B:")
    B = [list(map(float, input().split())) for _ in range(n)]
    C = nhan_ma_tran(A, B)
    print("A * B =")
    for row in C:
        print(*row)
if __name__ == "__main__":
    main()

# BÀI 5:
def chuyen_vi(A):
    m = len(A)
    n = len(A[0])
    # Tạo ma trận n × m
    T = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(m):
        for j in range(n):
            T[j][i] = A[i][j]
    return T

def main():
    m = int(input("Nhap so hang m: "))
    n = int(input("Nhap so cot n: "))
    print("Nhap ma tran A:")
    A = [list(map(float, input().split())) for _ in range(m)]
    T = chuyen_vi(A)
    print("Chuyen vi A^T:")
    for row in T:
        print(*row)

if __name__ == "__main__":
    main()

BÀI 1:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int A[100][100]; // Giả sử kích thước tối đa 100x100

    cout << "Nhap cac phan tu cua ma tran A:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ma tran A vua nhap:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

BÀI 2:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int A[100][100], B[100][100], C[100][100];

    cout << "Nhap ma tran A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    cout << "Nhap ma tran B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> B[i][j];
        }
    }

    // Cộng ma trận
    cout << "Tong A + B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Trừ ma trận
    cout << "Hieu A - B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

BÀI 3:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    double c;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    double A[100][100];
    cout << "Nhap ma tran A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    cout << "Nhap so thuc c: ";
    cin >> c;

    cout << "Ma tran c*A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << A[i][j]*c << " ";
        }
        cout << endl;
    }

    return 0;
}
