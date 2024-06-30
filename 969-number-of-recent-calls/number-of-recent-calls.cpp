class RecentCounter {
public:
queue<int>qq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
      int temp=t-3000;
      qq.push(t);
      while(qq.front()<temp)
      {
        qq.pop();
      }
      return qq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */