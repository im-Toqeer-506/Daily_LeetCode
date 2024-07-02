class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> map;
        int i = 0, j = 0;
        int n = s.size();
        int count = 0;
        while (i < n) {
            map[s[i]]++;
            if (i - j + 1 == 3) {
                if (map.size() == 3) {
                    count++;
                }
                map[s[j]]--;
                if (map[s[j]] == 0) {
                    map.erase(s[j]);
                }
                j++;
            }
            i++;
        }

        return count;
    }
};