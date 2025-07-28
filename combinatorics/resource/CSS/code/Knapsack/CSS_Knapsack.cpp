#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long, vector<int>> knapsack(int n, int W, const vector<int>& weights, const vector<int>& values) {
    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));    

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i-1][j]; 
            if (j >= weights[i-1]) { 
                dp[i][j] = max(dp[i][j], dp[i-1][j - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    vector<int> selected_items;
    int w = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) { 
            selected_items.push_back(i-1);
            w -= weights[i-1];
        }
    }
    reverse(selected_items.begin(), selected_items.end());
    
    return {dp[n][W], selected_items}; 
}

int main() {
    int n = 4;
    int W = 7;
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    
    auto [max_value, items] = knapsack(n, W, weights, values);
    cout << "Maximum value: " << max_value << endl;
    cout << "Selected items (0-based indices): ";
    for (int item : items) {
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}