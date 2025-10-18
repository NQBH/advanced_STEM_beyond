#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "nhập kích thước ma trận: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    cout << "nhập phần tử ma trận mới nhập:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    bool cheo = true;
    bool tgtren = true;
    bool tgduoi = true;
    bool doixung = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i != j && A[i][j] != 0) {
                cheo = false;
            }

            if (i > j && A[i][j] != 0) {
                tgtren = false;
            }

            if (i < j && A[i][j] != 0) {
                tgduoi = false;
            }
            
            if (A[i][j] != A[j][i]) {
                doixung = false;
            }
        }
    }

    cout << "ma trận chéo: " << (cheo ? "true" : "false") << endl;
    cout << "ma trận tam  giác trên: " << (tgtren ? "true" : "false") << endl;
    cout << "ma trận tam giác dưới: " << (tgduoi ? "true" : "false") << endl;
    cout << "ma trận đối xứng: " << (doixung ? "true" : "false") << endl;

    return 0;
}