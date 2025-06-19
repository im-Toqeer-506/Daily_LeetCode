class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // we are using this as a sliding window!
        unordered_set<int> st;
        int i = 0, j = 0;
        while (j < nums.size()) {
            //if window side exceed k then shrink it 
            if (abs(i - j) > k) 
            {
                st.erase(nums[i]);
                i++;//move the window one step farwed to shrink from left
            }
            //if number already in window 
            //then we font number inn the same range of k
            if (st.find(nums[j]) != st.end()) {
                return true;
            }
            st.insert(nums[j]);
            j++;//move ethe right farwed to increrse win
        }
        return false;
    }
};
