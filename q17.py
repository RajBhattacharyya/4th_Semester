def min_cost(cost, m, n):
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Base case: start position (0, 0)
    dp[0][0] = cost[0][0]

    # Initialize first column of dp array
    for i in range(1, m + 1):
        dp[i][0] = dp[i-1][0] + cost[i][0]

    # Initialize first row of dp array
    for j in range(1, n + 1):
        dp[0][j] = dp[0][j-1] + cost[0][j]

    # Build the dp array
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1])

    return dp[m][n]

# Example usage
cost = [[1, 2, 3],
        [4, 8, 2],
        [1, 5, 3]]
m, n = 2, 2  # destination position

print("Minimum cost to reach ({}, {}): {}".format(m, n, min_cost(cost, m, n)))
