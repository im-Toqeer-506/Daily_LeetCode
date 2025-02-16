class Solution {
public:
    int getSum(int a, int b) {
       int c=0;
       while(b!=0)
       {
        c=a&b;//carry
        a=a^b;//add bits without carry
        b=c<<1;//move the carry to left
       }
       return a;
    }
};
