#include "iostream"
#include "math.h"
using namespace std;

double dao_ham(int a[],int n, double x0){
	double result=0;
	for (int i=0;i<n;i++){
		result += i*a[i]*pow(x0,i-1);
	}
	return result;
}

double gioi_han(int a[], int b[], int n_a, int n_b, double x0){
    double P = dao_ham(a,n_a,x0);
    double Q = dao_ham(b,n_b,x0);
    if (Q == 0){
        cout << "invalid" << endl;
        return 0;
    }else{
        return P / Q;
    }
}

int main(){
    int a[] = {1, -4, 6, -4, 1};  
    int b[] = {1, -2, 1};  
    int n_a = sizeof(a) / sizeof(a[0]);  
    int n_b = sizeof(b) / sizeof(b[0]);  
    double x0 = 1;
    double value = gioi_han(a, b, n_a, n_b, x0);
    cout << value << endl;
    return 0;
}