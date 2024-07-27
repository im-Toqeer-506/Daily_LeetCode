class Solution {
public:
    int memorization(int n, vector<int>& memo) {
        if (n < 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (memo[n] != -1)
            return memo[n];
        memo[n] = memorization(n - 1, memo) + memorization(n - 2, memo) +
                  memorization(n - 3, memo);
        return memo[n];
    }
    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);
        return memorization(n, memo);
    }
};