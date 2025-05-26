#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    while(true){
        int n; cin>>n;
        vector<int> a;
        if(n==0) break;
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j++){
                    if(j%i==0) prime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(prime[i]) a.push_back(i);
        }
        int count=0;
        int sum;
        for(int i=0;i<a.size();i++){
            sum=a[i];
            if (sum == n) count++;
            for (int j = i + 1; j < a.size() && sum < n; j++){
                sum += a[j];
                if (sum == n){
                    ++count;
                    break;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}