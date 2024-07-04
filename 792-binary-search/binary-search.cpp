class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int h=n-1;
        while(low<=h){
            int mid=(low+h)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid])
                low=mid+1;
            else h=mid-1;    
        }
        return -1;
    }
};