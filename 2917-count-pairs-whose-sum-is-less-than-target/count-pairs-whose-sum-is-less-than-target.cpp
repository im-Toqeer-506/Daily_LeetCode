class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // [-1,1,1,2,3]
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                cout<<count<<" ";
                count+=right-left;
                left++;
             
            } else {
                right--;
            }
        }
        return count;
    }
};