class Solution {
public:
   int counterBits(int n){
    int cnt=0;
    while(n)
     {
       int bit=n&1;
       if(bit)cnt++;
       n=n>>1;
        
     }
     return cnt;
   }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<n+1;i++)
        {
            ans[i]=counterBits(i);
        }
        return ans;
        
    }
};
