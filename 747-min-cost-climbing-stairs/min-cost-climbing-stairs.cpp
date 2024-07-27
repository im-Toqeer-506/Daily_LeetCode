vector<int> dp(1001, -1); 
class Solution {
public:
    int minCost(vector<int>& cost, int n) {
        if (dp[n] != -1) // to check if already calculated
            return dp[n];

        if (n == 0)
            return dp[n] = cost[0];
        if (n == 1)
            return dp[n] = cost[1];

        return dp[n] = min(minCost(cost, n - 1) + cost[n], minCost(cost, n - 2) + cost[n]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        fill(dp.begin(), dp.end(), -1); // Reset the memoization array
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};