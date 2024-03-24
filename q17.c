#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

// Function to find minimum of two numbers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to find the minimum cost path
int minCost(int cost[ROW][COL], int m, int n) {
    int i, j;
    int dp[ROW][COL];

    // Base case: start position (0, 0)
    dp[0][0] = cost[0][0];

    // Initialize first column of dp array
    for (i = 1; i <= m; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];

    // Initialize first row of dp array
    for (j = 1; j <= n; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

    // Build the dp array
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    int cost[ROW][COL] = {{1, 2, 3},
                          {4, 8, 2},
                          {1, 5, 3}};
    int m = 2, n = 2; // destination position

    printf("Minimum cost to reach (%d, %d): %d\n", m, n, minCost(cost, m, n));
    return 0;
}
