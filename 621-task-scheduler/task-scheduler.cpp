class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        //phase 1
       vector<int>map(26,0);
       for(auto ch:tasks)
       {
        map[ch-'A']++;
       }
       int time=0;
       //    Phase 2
       priority_queue<int>pq;
       for(int i=0;i<26;i++)
       {
        if(map[i]>0)
        {
        pq.push(map[i]);
        }
       }
       //Phase 3
       while(!pq.empty())
       {
        vector<int>temp;
        for(int i=1;i<=n+1;i++)
        {
            if(!pq.empty())
            {
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
        for(auto &f:temp)
        {
            if(f>0)
            {
                pq.push(f);
            }
            
        }
        if(pq.empty())
        {
            time+=temp.size();
        }
        else{
            time+=n+1;
        }
       }
       return time;
    }
};