class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string result;
        string f=strs.front();
        string e=strs.back();
        for (int i = 0; i < f.size(); ++i) {
        if (f[i] != e[i])
        break;
            result += f[i];
        }
        return result;
    }
};