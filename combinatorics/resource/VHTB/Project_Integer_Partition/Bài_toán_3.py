def count_self_conjugate_partitions(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for k in range(1, n + 1, 2):
        for i in range(n, k - 1, -1):
            dp[i] += dp[i - k]
    return dp[n]

def generate_self_conjugate_partitions(n):
    def is_self_conjugate(partition):
        width = partition[0]
        height = len(partition)
        grid = [[0] * width for _ in range(height)]
        for i in range(height):
            for j in range(partition[i]):
                grid[i][j] = 1
        for i in range(height):
            for j in range(partition[i]):
                if j >= len(grid): return False
                if i >= len(grid[j]): return False
                if grid[i][j] != grid[j][i]: return False
        return True

    def helper(n, max_val, path, result):
        if n == 0:
            if is_self_conjugate(path):
                result.append(list(path))
            return
        for i in range(min(n, max_val), 0, -1):
            if not path or i <= path[-1]:
                path.append(i)
                helper(n - i, i, path, result)
                path.pop()

    result = []
    helper(n, n, [], result)
    return result

n = 7
print("Tổng số phân hoạch tự liên hợp của", n, "là:", count_self_conjugate_partitions(n))
print("Kết quả phân hoạch tự liên hợp:")
for p in generate_self_conjugate_partitions(n):
    print(p)
