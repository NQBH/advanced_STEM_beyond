#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << "nhap n:" << n << endl;
    double a, maxVal, minVal;

    cin >> a;
    maxVal = a;
    minVal = a;
    for(int i = 1; i < n; i++){
        cin >> a;
        if(a > maxVal){
            maxVal = a;
        }
        if(a < minVal){
            minVal = a;
        }

    }
    cout << "max: " << maxVal << endl;
    cout << "min: " << minVal << endl;
    return 0;
}
