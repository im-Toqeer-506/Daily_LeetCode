class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        int sti = 0;
        int endi = k;
        while (endi < nums.size()) {
            sum -= nums[sti];
            sti++;
            sum+=nums[endi];
            endi++;
            maxSum=max(maxSum,sum);
        }
        return (double)maxSum/k;
    }
};