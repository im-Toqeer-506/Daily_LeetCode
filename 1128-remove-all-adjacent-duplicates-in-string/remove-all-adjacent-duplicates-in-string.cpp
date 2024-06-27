class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto c:s) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }

        }
        string r="";
        while(!stk.empty()){
            r=stk.top()+r;
            stk.pop();
        }
        return r;
    }
};