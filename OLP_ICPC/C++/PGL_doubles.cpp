#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

int main() {
    while (true) {
        vector<int> a;
        bool exit=false;
        while(true){
            int x; cin>>x;
            a.push_back(x);
            if(x==0) break;
            if(x==-1){
                exit=true;
                break;
            }
        }
        if(exit) break;
        else{
            sort(a.begin(),a.end());
            int count=0;
            for(ll i=0;i<a.size();i++){
               for(ll j=0;j<a.size();j++){
                   if(i!=j && a[j]==a[i]*2) count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}