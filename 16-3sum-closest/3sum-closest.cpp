class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int cs= 100000;
        
        for(int i = 0; i<n-2; i++) {
            
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(target-sum) < abs(target-cs)) {
                    cs = sum;
                }
                
                if(sum > target)
                    r--;
                else
                    l++;
            }
        }
        return cs;
    }
};