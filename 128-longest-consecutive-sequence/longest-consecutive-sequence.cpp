class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        unordered_set<int> hashSet;
        hashSet.insert(nums.begin(), nums.end());
        int sequance = 0;
        for (auto num : nums) {
            int currNum = num;
            int currSequance = 1;
            if (hashSet.find(num - 1) == hashSet.end()) {

                while (hashSet.find(currNum + 1) != hashSet.end()) {
                    currNum += 1;
                    currSequance += 1;
                }
                sequance = max(sequance, currSequance);
            }
        }
        return sequance;
    }
};
