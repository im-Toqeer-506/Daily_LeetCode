class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        for (int j = 0; j < n; j++) {
            rightSum = totalSum - leftSum - nums[j];
            cout << rightSum << " : " << leftSum << endl;
            if (rightSum == leftSum)
                return j;
            leftSum += nums[j];
        }
        return -1;
    }
};