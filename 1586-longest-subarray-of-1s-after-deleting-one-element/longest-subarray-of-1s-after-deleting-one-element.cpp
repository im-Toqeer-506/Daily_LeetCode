class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cntzero = 0;
        int len_max = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0)
                cntzero++;
            while (cntzero > 1) {
                if (nums[i] == 0) {
                    cntzero--;
                }

                i++;
            }
            len_max = max(len_max, j - i);
            cout << len_max << " " << endl;
        }
        return len_max;
    }
};