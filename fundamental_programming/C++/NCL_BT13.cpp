#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n ,m, M, i = 0;
	cout << "nhập n :" ;
	cin >> n;
	cout <<"nhập m :";
	cin >> m;
	cout << "Nhập M :";
	cin >> M;
	
	
	double S = 0;
	while (i <= n) {
        if (S + pow(i, m) <= M) {
            S += pow(i, m);
        } else break;
        i += 1;
    }

    cout << " kết quả : " << S;

}