class Solution{
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return nums[0];
        
        vector<int> memo(n); 
        
        memo[0] = nums[0]; // Pehla house loot lo
        memo[1] = max(nums[0], nums[1]); // Dusre house ke liye decision
        
        for (int i = 2; i < n; i++) {
            memo[i] = max(memo[i-2] + nums[i], memo[i-1]);
        }
        return memo[n-1]; // Last house tak ka  paisa
    }
};
