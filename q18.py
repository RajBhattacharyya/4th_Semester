def minCoins(coins, V):
    # Create a dp list to store minimum number of coins required
    dp = [float('inf')] * (V + 1)

    # Base case: dp[0] = 0
    dp[0] = 0

    # Iterate through each value from 1 to V
    for val in range(1, V + 1):
        # Iterate through each coin denomination
        for coin in coins:
            # If the current coin denomination can be used to make change for current value
            if coin <= val:
                # Update dp[val] to be the minimum of its current value and dp[val - coin] + 1
                dp[val] = min(dp[val], dp[val - coin] + 1)

    # Return the minimum number of coins required to make change for value V
    return dp[V]

# Example usage
coins = [1, 2, 5]  # Denominations of coins
V = 11  # Value for which change is required
print("Minimum number of coins required:", minCoins(coins, V))
