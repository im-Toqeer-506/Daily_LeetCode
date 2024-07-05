class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int sum=0;
        int count=0;
        map[sum]=1;
        for(auto num:nums){
          sum=sum+num;
          int diff=sum-k;
          count =count+map[diff];
          map[sum]++;

        }
        return count;

    }
};