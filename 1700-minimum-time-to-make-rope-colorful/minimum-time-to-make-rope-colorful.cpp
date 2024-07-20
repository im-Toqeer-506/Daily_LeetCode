class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int time = 0;
        int prevMax = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && colors[i] != colors[i - 1]){
                prevMax=0;
            }

            time += min(prevMax, neededTime[i]);
            prevMax = max(prevMax, neededTime[i]);
        }
        return time;
    }
};