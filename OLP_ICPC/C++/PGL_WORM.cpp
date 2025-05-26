#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        string s;cin>>s;
        vector<int> a(n);
        a.clear();
        int count=0;
        for(int i=0;i<n;i++){
            count++;
            if(s[i]!=s[i+1]){
                a.push_back(count);
                count=0;
            }
        }
        int sum=0;
        for(int i=1;i<=a.size();i+=2){
            sum+=min(a[i],a[i-1]);
        }
        cout<<sum<<endl;
    }
    return 0;
}