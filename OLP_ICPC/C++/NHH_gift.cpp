#include <iostream>
#include <vector>
using namespace std;


int main(){
    int t; cin>>t;
    while (t--){
        int n, k;
        cout<<"Input number of presents: "; cin>>n;
        cout<<"Input the value_gap: "; cin>> k;

        vector<int> pri_vec(n);
        for(int i=0; i<n; i++){
            cin>>pri_vec[i];
        }


        int count_valid =0;
        vector<int> valid_indices;
        for (int i=0; i<n; i++){
            if (pri_vec[i] %2 ==0){
                if (valid_indices.empty()){
                    valid_indices.push_back(i);
                    count_valid++;
                } else {
                    int last_valid_val = pri_vec[valid_indices.back()];
                    if (abs(pri_vec[i] - last_valid_val) == k){
                        valid_indices.push_back(i);
                        count_valid++;
                    }
                }
            }
        }
        cout<<count_valid<<endl;
    }


    return 0;
}
