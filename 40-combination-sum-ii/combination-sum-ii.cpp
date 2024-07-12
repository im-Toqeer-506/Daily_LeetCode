class Solution {
public:
    void Backtrack(vector<vector<int>>& result, vector<int>& current,
                   vector<int>& candidates, int target, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
             if (i > index && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                Backtrack(result, current, candidates, target - candidates[i],i+1);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        Backtrack(result, current, candidates, target, 0);
        return result;
    }
};