#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4 // Number of cities

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum cost for TSP
int tsp(int graph[N][N]) {
    int dp[1 << N][N]; // dp[mask][i] represents the minimum cost of visiting all cities in the subset mask and ending at city i
    int mask, i, j;

    // Initialize dp array with maximum integer value
    for (mask = 0; mask < (1 << N); mask++) {
        for (i = 0; i < N; i++) {
            dp[mask][i] = INT_MAX;
        }
    }

    // Base case: starting from city 0
    dp[1][0] = 0;

    // Iterate through all possible subsets of cities
    for (mask = 1; mask < (1 << N); mask++) {
        for (i = 0; i < N; i++) {
            if (mask & (1 << i)) { // If city i is in the current subset
                for (j = 0; j < N; j++) {
                    if (mask & (1 << j) && i != j) { // If city j is in the current subset and is not the same as city i
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + graph[j][i]);
                    }
                }
            }
        }
    }

    // Find the minimum cost to return to city 0
    int min_cost = INT_MAX;
    for (i = 1; i < N; i++) {
        min_cost = min(min_cost, dp[(1 << N) - 1][i] + graph[i][0]);
    }

    return min_cost;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("Minimum cost for TSP: %d\n", tsp(graph));

    return 0;
}
