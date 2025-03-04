class Solution {
public:
    int robLinear(vector<int>& nums, int s, int e) {
        int p2 = 0; 
        int p1 = 0; 
        for (int i = s; i <= e; i++) {
            int curr = max(p1, p2 + nums[i]); 
            p2 = p1; 
            p1 = curr;  
        }
        return p1; 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        // (phely first ko chorna hai ,then dosery ko chorna hai)
        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
};
