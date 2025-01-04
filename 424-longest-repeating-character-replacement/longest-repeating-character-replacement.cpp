class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0;
        int maxFreq = 0;
        int maxWin = 0;
        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            int windLen = r - l + 1;
            if (windLen - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }
            windLen = r - l + 1;
            maxWin= max(maxWin, windLen);
        }
        return maxWin;
    }
};
