#include <bits/stdc++.h>
#define for(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main(){
    int num_row, num_col;
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    if(num_row!=num_col) cout << "End program (p/s: row = col)";
    else{
        for(i,num_row)
            for(j,num_col)
                cin >> a[i][j];
        // Ma tran duong cheo
        bool check = false;
        for(i,num_row)
            for(j,num_col)
                if((i>j || i<j) && a[i][j]==0)
                    check = true;
        if(check) cout << "Ma tran duong cheo";
        // Ma tran tam giac tren
        bool check_above = false;
        for(i,num_row)
            for(j,num_col)
                if(i>j && a[i][j]==0)
                    check_above = true;
        if(check_above) cout << "Co ma tran tam giac tren\n";
        //Ma tran tam giac duoi
        bool check_below = false;
        for(i,num_row)
            for(j,num_col)
                if(i<j && a[i][j]==0)
                    check_below = true;
        if(check_below) cout << "Co ma tran tam giac duoi\n";
        vector<vector<int> > at(num_row, vector<int>(num_col));
        for(i, num_row)
            for(j, num_col)
                at[i][j] = a[j][i];
        if(at==a) cout << "Ma tran doi xung\n";
    }
}
