#include <iostream> 
#include <vector> 
#include <string> 
#include <cmath>
using namespace std; 
#define ll long long 
#define endl "\n"

// Function to calculate factorial of a number
ll factorial(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n; i++)  result *= i;
    return result;
}

void backtrack(vector<string> &res, string &current, ll len, ll count[26]) {
    // nếu đủ độ dài qua trường hợp tiếp theo 
    if (current.size() == len) {
        res.push_back(current);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            current.push_back('a' + i);    
            count[i]--;                          // giảm count_app của ký tự
            backtrack(res, current, len, count); // đệ quy đến hết count_app của ký tự đó
            count[i]++;                          // undo trong backtrack
            current.pop_back();                  // bỏ ký tự mới thêm để thử nhánh khác
        }
    }
}

int main(){ 
    string s; cin >> s; 

    ll count[26] = {0}, count_app[26] = {0}; 
    for (ll i = 0; i < s.length(); i++){
        char c = s[i]; 
        count[c - 'a']++; // đếm số lần xuất hiện 
    }

    ll sum = 0; 
    for (ll j = 0; j < 26; j++) {
        if (count[j] != 0) {
            count_app[j] = count[j];
            sum += count_app[j];
        } 
    } 

    // factorial 
    ll repeat = 1, res1 = 0; 
    ll total_fact = factorial (sum); 
    // cout << total_fact;
    for (ll i = 0; i < 26; i++){
        repeat *= factorial (count_app[i]);
    }
    res1 = total_fact / repeat;
    cout << res1 << endl; 

    vector <string> res;
    string cur = "";
    backtrack(res, cur, s.length(), count);
    for (string &str : res) cout << str << endl;

    return 0;
}