class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        unordered_set<string>look;
        unordered_set<string> bef;
        vector<string> res;

        for (int i = 0; i <= s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            if (look.find(sub) != look.end()) {
                bef.insert(sub);
            } else {
                look.insert(sub);
            }
        }

        res = vector<string>(bef.begin(), bef.end());
        return res;
    }
};
