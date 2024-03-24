def isSubsetSum(set, n, sum):
    dp = [[False] * (sum + 1) for _ in range(n + 1)]

    # Base case: when sum is 0, subset is always possible
    for i in range(n + 1):
        dp[i][0] = True

    # Base case: when set is empty, subset is not possible for sum > 0
    for j in range(1, sum + 1):
        dp[0][j] = False

    # Build the dp array
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            if set[i - 1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - set[i - 1]]

    return dp[n][sum]

# Example usage
set = [3, 34, 4, 12, 5, 2]  # Given set of non-negative integers
sum = 9  # Target sum
n = len(set)  # Number of elements in the set

if isSubsetSum(set, n, sum):
    print("Subset with sum", sum, "exists.")
else:
    print("No subset with sum", sum, "exists.")
