class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> tkw;
        unordered_map<int, int> track;
        if (n == 1)
            return 1;
        for (auto t : trust) {
            int a = t[0];
            int b = t[1];
            tkw.insert(a);
            track[b]++;
        }
        for (int i = 0; i <= n; i++) {
           if (tkw.find(i) == tkw.end() && track[i] == n - 1)
            return i;
        }

        return -1;
    }
};