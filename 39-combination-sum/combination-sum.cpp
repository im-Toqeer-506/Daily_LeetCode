class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(result, current, candidates, target - candidates[i], i);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, candidates, target, 0);
        return result;
    }
};
