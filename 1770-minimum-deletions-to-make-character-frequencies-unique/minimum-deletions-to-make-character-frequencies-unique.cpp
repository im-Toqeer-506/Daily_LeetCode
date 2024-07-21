class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char,int>freq;
       for(auto ch:s){
        freq[ch]++;
       }
       int deletion=0;
       unordered_map<int,bool>usedfreq;
        for(auto& pair:freq){
        int count =pair.second;
        while(usedfreq[count]){
            count--;
            deletion++;
        }
        if(count>0){
            usedfreq[count]=true;

        }
       }
       return deletion;

    }
};