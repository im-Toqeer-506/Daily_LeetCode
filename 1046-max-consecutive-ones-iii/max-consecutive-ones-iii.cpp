class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntzero = 0;
        int start = 0;
        int cntone = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cntzero++;
            }
            while (cntzero > k) {
                if (nums[start] == 0) {
                    cntzero--;
                }
                    start++;
            }
            cntone = max(cntone, i - start + 1);
        }
        return cntone;
    }
};