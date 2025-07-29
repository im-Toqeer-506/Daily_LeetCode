class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
       int l=0;
       int r=n-1;
       int lmax=height[l];
       int rmax=height[r];  
        int ans = 0;
while(l<r) {
         lmax=max(height[l],lmax);
         rmax=max(height[r],rmax);
         if(lmax<rmax){
            ans+=lmax-height[l];
            l++;
         }else{
            ans+=rmax-height[r];
            r--;

         }
        }
        return ans;
    }
};
