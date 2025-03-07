class Solution {
public:
    bool solve(string &str,int i,int j)
    {
        if(i>=j){return true;}
        if(str[i]==str[j])
     {   return solve(str,i+1,j-1);}
        return false;

    }
    string longestPalindrome(string s) 
    {
     int n=s.length();
     int ml=0;
     int sp=0;
   for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > ml) {
                        ml = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
    return s.substr(sp, ml);
    }
};