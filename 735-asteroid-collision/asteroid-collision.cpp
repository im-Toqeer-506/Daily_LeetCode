class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
       
        for (auto s : asteroids) {
           while(!stk.empty() && s < 0 && stk.top() > 0)  {
                 int sum = s + stk.top();
               if(sum < 0) {
                    stk.pop();
                } else if(sum > 0) {
                    s = 0;
                    break;
                } else {
                    stk.pop();
                    s = 0;
                }
            }
            if (s != 0)
                stk.push(s);
        }
        int n = stk.size();
        vector<int> result(n);
        int i = n-1;
        while (!stk.empty()) {
            result[i] = stk.top();
            stk.pop();
            i--;
        }
        return result;
    }
};
