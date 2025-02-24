class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1){
            if(st.find(n)!=st.end())
            {
                return false;
            }
            st.insert(n);
            int sum=0;
            while(n>0)
            {
            int num=n%10;
            sum+=num*num;

            n=n/10;
            }
            n = sum; 

        }
        return true;
    }
};
