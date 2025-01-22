class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        if(points.size()==0)return ans;
        
        priority_queue<pair<int,pair<int,int>>>PQ;
        for(int i=0;i<points.size();i++)
        {  
            //just to calculating the distence by self as (0^2+2^2)=4
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(PQ.size()<k)
            {PQ.push({dist,{points[i][0],points[i][1]}});}
            else{
                if(dist<PQ.top().first)
                {
                    PQ.pop();
                    PQ.push({dist,{points[i][0],points[i][1]}});
                }
            }
        }
        while(!PQ.empty())
        {
            ans.push_back({PQ.top().second.first,PQ.top().second.second});
            PQ.pop();
        }
        return ans;
    }
};