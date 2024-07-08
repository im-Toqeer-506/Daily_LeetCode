class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> integers;

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 &&
                nums[i] == nums[i - 1]) // same as react conditionl rendering
                continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    integers.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return integers;
    }
};
