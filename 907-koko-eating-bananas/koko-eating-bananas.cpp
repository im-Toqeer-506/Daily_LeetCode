class Solution {
public:
    bool CanEatBananas(vector<int>& piles, int mid,int h)
    {
        int actualHours=0;
        for(auto x:piles)
        {
            actualHours+=x/mid;
        if(x%mid!=0)
        {
            actualHours++;
        }
        }
        return actualHours<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n=piles.size();
        int l=1;
        int r = *max_element(piles.begin(), piles.end()); 
        while(l<r)
        {
            int mid=(l+r)/2;
            if(CanEatBananas(piles,mid,h))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
        
    }
};
