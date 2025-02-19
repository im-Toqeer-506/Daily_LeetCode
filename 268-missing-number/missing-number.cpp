class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int zor=0;
        for (int i = 0; i <= nums.size(); i++) {
        zor = zor ^ i;
        }
        for (int num : nums) {
        zor = zor ^ num;
        }
        return zor;
    }
};
