class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
    unordered_map<char,int>hashCount;
   
    for(auto ch1:s)
    {
        hashCount[ch1]++;
    }
    for(auto ch2:t)
    {
        hashCount[ch2]--;
        
    }
    for(auto pair:hashCount)
    {
        if(pair.second !=0 )
        return false;
       
    }

    return true;

    }
};
