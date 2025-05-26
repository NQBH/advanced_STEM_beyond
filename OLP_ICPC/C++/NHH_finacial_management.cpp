#include <iostream> 
#include <vector>
#include <cmath>
using namespace std; 

int main(){
    vector<float> close_balance(12);
    
    for (int i=0; i<12; i++)
        cin >> close_balance[i];

    double sum = 0;
    for (int i=0; i<12; i++){
        sum += close_balance[i];
    }

    double res = sum/12;
    cout << "$" << res;
    return 0;
}