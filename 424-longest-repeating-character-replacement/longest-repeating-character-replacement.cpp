class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxWin = 0;
        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int winSize = right - left + 1;
            int replace = winSize - maxFreq;

            if (replace > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxWin = max(maxWin, right - left + 1); 
        }

        return maxWin;
    }
};
