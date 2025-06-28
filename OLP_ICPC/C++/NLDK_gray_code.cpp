#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int step = 4, n;
    cin >> n;
    //final size of the storing vector
    int sizer = pow(2, n);
    
    //storing vector
    vector<string> ini(2);
    
    //new/temp vector to store the newly generated code
    vector<string> final(4);
    
    //first 2 gray code: 0 and 1
    ini[0] = "0";
    ini[1] = "1";

    //creating more gray code
    while (step <= sizer) {
        // add 0 to the start of the stored code
        int posi = 0;
        for (posi; posi < step/2; ++posi) {
            final[posi] = '0' + ini[posi];
        }
        
        // add 1 to the start of the stored code
        int jump = 1;
        for (posi; posi < step; ++posi) {
            final[posi] = '1' + ini[posi - jump];
            jump += 2;
        }
        
        //making the size of the storing vector = the size of the new vector
        ini.resize(step);
        
        //storing result
        ini = final;
        
        //upsizing the vector to store the next codes
        step *= 2;
        final.resize(step);
    }
    //Output
    frs(i, 0, sizer) {cout << ini[i] << el}
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
