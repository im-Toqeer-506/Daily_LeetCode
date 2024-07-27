class Solution {
public:
    int memoRization(int n, vector<int>& memo) {
        if (n <= 1)
            return  n;
        if (memo[n] != -1)return memo[n];

        memo[n] = memoRization(n - 1, memo) + memoRization(n - 2, memo);
        return memo[n];
    }
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return memoRization(n, memo);
    }
};