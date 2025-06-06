#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
(\_/)
( * *)
 / ?? <3
*/
void IOfile()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen("b.inp","r",stdin);
    freopen("b.out","w",stdout);
}
void Task1(){
    ll k,g=1;
    int n;
    cin >>n>>k;
    for (int i=2;i<n;i++) g*=i;
    vector<int> Num;
    vector<int> ans;
    Num.push_back(0);
    for (int i=0;i<n;i++) Num.push_back(i+1);
    while (n>0)
    {
        for (int i=1;i<=n;i++)
        if (g*i>=k)
        {
            ans.push_back(Num[i]);
           // cout <<n<<" "<<k<<" "<<g<<endl;
            //cout<<Num[i]<<" ";
            Num.erase(Num.begin()+i);
            k=k-g*(i-1);
            if (n-1>0) g/=(n-1);
            break;
        }
        n--;
    }
    for (int x:ans) cout<<x<<" ";
    cout<<endl;
}
void Task2(){
    int n;
    cin >> n;
    int a[n+2];
    int p[n+2];
    ll g=1;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        g*=i;
    }
    p[1]=a[1];
    p[n]=1;
    // thứ tự tại thời điểm n>0
    for (int i=2;i<n;i++)
    {
        int pos=1;
        for (int j=i+1;j<=n;j++)
            if (a[i]>a[j]) pos++;
        p[i]=pos;
    }
    // đáp án / stt/ vị trí trong  n!
    ll ans=1;
    int i=0;
    while (n>0)
    {
        i++;
        ans+=(g/n)*(p[i]-1);
        g/=n;
        n--;
    }
    cout <<ans<<endl;
}
int main()
{
    int t;
    //IOfile();
    cin >>t;
    while (t--)
    {
        int T;
        cin >>T;
        if (T==1) Task1();
        else Task2();
    }
	return 0;
}
