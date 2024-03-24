def tsp(graph):
    n = len(graph)
    
    # Initialize memoization table
    dp = [[float('inf')] * n for _ in range(1 << n)]
    dp[1][0] = 0  # Base case: starting from city 0

    # Iterate through all possible subsets of cities
    for mask in range(1, 1 << n):
        for i in range(n):
            if mask & (1 << i):  # If city i is in the current subset
                for j in range(n):
                    if mask & (1 << j) and i != j:  # If city j is in the current subset and is not the same as city i
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + graph[j][i])

    # Find the minimum cost to return to city 0
    min_cost = min(dp[(1 << n) - 1][i] + graph[i][0] for i in range(1, n))

    return min_cost

# Example usage
graph = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]
print("Minimum cost for TSP:", tsp(graph))
