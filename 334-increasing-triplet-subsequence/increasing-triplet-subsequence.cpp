class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // m<n<o
        //1,2,3
        //0,5,6
        int m=INT_MAX;
        int n=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int o=nums[i];
            if(o<=m)
            {
                m=o;
            }
            else if(o<=n)
            {
                n=o;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};