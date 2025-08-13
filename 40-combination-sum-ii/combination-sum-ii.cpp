class Solution {
public:
    void backtrack(vector<int>& candidates,vector<vector<int>>&Ans,vector<int>&temp,int target,int start){
//EdgeCase -->specific 
if(target==0)
{
Ans.push_back(temp);
      return;
}
for(int i=start;i<candidates.size();i++){
    if(i>start &&candidates[i]==candidates[i-1])continue;
    //when the numbers becomes gratter then target 
    if(candidates[i]>target)break;
    temp.push_back(candidates[i]);
    backtrack(candidates,Ans,temp,target-candidates[i],i+1);
    temp.pop_back();
}
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
 //sort to check duplicates
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> Ans;
    vector<int>temp;
    backtrack(candidates,Ans,temp,target,0);
    return Ans;
   

    }
};
