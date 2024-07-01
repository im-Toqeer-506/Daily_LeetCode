class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int temp = s[i] - 'a';
            arr[temp]++;
        }
        for (int i = 0; i < s.size(); i++) {
            int temp = s[i] - 'a';
            if (arr[temp] == 1)
                return i;
        }
        return -1;
    }
};