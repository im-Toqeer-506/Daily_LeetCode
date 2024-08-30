class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        if (s1.length() > s2.length())
            return false;
        int left = 0;
        int right = 0;
        while (right < s1.length()) {
            hash1[s1[right] - 'a'] += 1;
            hash2[s2[right] - 'a'] += 1;
            right += 1;
        }
        right -= 1;
        while (right < s2.length()) {
            if (hash1 == hash2)
                return true;
            right += 1;
            if (right != s2.length()) {
                hash2[s2[right] - 'a'] += 1;
            }
            hash2[s2[left] - 'a'] -= 1;
            left += 1;
        }
        return false;
    }
};