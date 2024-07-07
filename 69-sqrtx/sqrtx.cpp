class Solution {
public:
    int mySqrt(int x) {
         if (x == 0) return 0; 
        int l=0;
        int h=x;
        while(l<=h){
            long mid=(l+h)/2;
            long val=(mid*mid);
            if(val<=x){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return h;
    }
};