#include <stdio.h>
#include <stdbool.h>

// Function to determine if there is a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Base case: when sum is 0, subset is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Base case: when set is empty, subset is not possible for sum > 0
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    // Build the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2}; // Given set of non-negative integers
    int sum = 9; // Target sum
    int n = sizeof(set) / sizeof(set[0]); // Number of elements in the set

    if (isSubsetSum(set, n, sum))
        printf("Subset with sum %d exists.\n", sum);
    else
        printf("No subset with sum %d exists.\n", sum);

    return 0;
}
