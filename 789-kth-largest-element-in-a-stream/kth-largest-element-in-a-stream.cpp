class KthLargest {
public:
    int m;
    priority_queue<int, vector<int>, greater<int>> PQ;
    KthLargest(int k, vector<int>& nums) {
        m=k;
        for(auto num:nums)
        {
            PQ.push(num);
            if(PQ.size()>k)PQ.pop();
        }
    }
    
   int add(int val) {
        PQ.push(val);
        if(PQ.size()>m)PQ.pop();
        return PQ.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
