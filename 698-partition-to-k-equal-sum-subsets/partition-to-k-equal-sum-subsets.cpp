class Solution {
public:
 bool helper(vector<int>& nums, int k, int tv,
                int curSum, vector<bool>& track, int index) {
        if (k == 0) return true;
        if (curSum > tv) return false;
        if (curSum == tv) return helper(nums, k - 1, tv, 0, track, 0);

        for (int i = index; i < nums.size(); ++i) {
            if (!track[i]) {
                track[i] = true;
                if (helper(nums, k, tv, curSum + nums[i], track, i + 1)) return true;
                track[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, maxNum = 0;
      vector<bool>track(nums.size());//track rakhay ga elemnts ka
        for (int num : nums) {
            sum += num; // calculating the  total sum
            maxNum = max(maxNum, num); // calculate the max number in the whole array ..
        }
        if (sum % k != 0 || maxNum > sum / k)//ager total sum k per pora pora divide na ho tu false hai
            return false;

        return helper(nums, k, sum / k, 0, track, 0);
    }
};