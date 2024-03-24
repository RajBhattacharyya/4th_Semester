#include <stdio.h>
#include <limits.h>

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find minimum number of coins required
int minCoins(int coins[], int m, int V) {
    // Create a dp array to store minimum number of coins required
    int dp[V + 1];

    // Initialize dp[0] as 0 (base case)
    dp[0] = 0;

    // Initialize all other values in dp array as INT_MAX
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }

    // Iterate through each value from 1 to V
    for (int i = 1; i <= V; i++) {
        // Iterate through each coin denomination
        for (int j = 0; j < m; j++) {
            // If the current coin denomination can be used to make change for current value
            if (coins[j] <= i) {
                // Update dp[i] to be the minimum of its current value and dp[i - coin] + 1
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Return the minimum number of coins required to make change for value V
    return dp[V];
}

int main() {
    int coins[] = {1, 2, 5}; // Denominations of coins
    int m = sizeof(coins) / sizeof(coins[0]); // Number of denominations
    int V = 11; // Value for which change is required

    printf("Minimum number of coins required: %d\n", minCoins(coins, m, V));
    return 0;
}
