class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int maximum=0;
      vector<bool>ans;
      for(auto num:candies){
        maximum=max(num,maximum);
      } 
      for(auto num:candies) {
        if(num+extraCandies>=maximum)
        ans.push_back(true);
        else
        ans.push_back(false);


      }
      return ans;

    }
};