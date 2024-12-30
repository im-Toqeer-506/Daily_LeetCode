class Solution {
public:
    int Solve(vector<int>& nums, int target, int l, int h) {
        if (l > h) return -1; 
        int mid = l + (h - l) / 2;
        
        if (nums[mid] == target) return mid;
        
       
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                return Solve(nums, target, l, mid - 1); 
            } else {
                return Solve(nums, target, mid + 1, h); 
            }
        } 
        
        else {
            if (nums[mid] < target && target <= nums[h]) {
                return Solve(nums, target, mid + 1, h); 
            } else {
                return Solve(nums, target, l, mid - 1); 
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        return Solve(nums, target, 0, nums.size() - 1);
    }
};
