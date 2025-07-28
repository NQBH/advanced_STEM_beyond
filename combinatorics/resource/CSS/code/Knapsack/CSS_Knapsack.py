def knapsack(n, W, weights, values):
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(W + 1):
            dp[i][j] = dp[i-1][j]  
            if j >= weights[i-1]: 
                dp[i][j] = max(dp[i][j], dp[i-1][j - weights[i-1]] + values[i-1])
    
    selected_items = []
    w = W
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i-1][w]: 
            selected_items.append(i-1)
            w -= weights[i-1]
    
    return dp[n][W], selected_items[::-1] 

# Ví dụ
if __name__ == "__main__":
    n = 4
    W = 7
    weights = [1, 3, 4, 5]
    values = [1, 4, 5, 7]
    
    max_value, items = knapsack(n, W, weights, values)
    print(f"Maximum value: {max_value}")
    print(f"Selected items (0-based indices): {items}")