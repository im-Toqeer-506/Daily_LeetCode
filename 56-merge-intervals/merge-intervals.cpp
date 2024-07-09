#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (const auto& in : intervals) {
            if (in[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], in[1]);
            } else {
                res.push_back(in);
            }
        }
        return res;
    }
};
