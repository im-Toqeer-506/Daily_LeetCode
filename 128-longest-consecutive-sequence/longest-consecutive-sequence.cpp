class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        unordered_map<int,bool> mp;
        int ln=0;
        for(auto num:nums)
        {
            mp[num]=false;
        }
         for (int num : nums) {
            if(mp[num])continue;
            int cl=1;
            mp[num]=true;
            // Agay Dakh 
            int n = num + 1;
            while (mp.count(n) && mp[n] == false) {
            cl++;
                mp[n] = true;
                n++;
            }
            // Pichay Dakh
            int p= num - 1;
            while (mp.count(p) && mp[p] == false) {
                cl++;
                mp[p] = true;
                p--;
            }
            ln = max(ln, cl);
         }
    return ln;
    }
};
