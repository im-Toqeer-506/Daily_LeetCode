class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>stk1,stk2;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                stk1.push(s[i]);
            }
            else if(!stk1.empty()){
                stk1.pop();
            }
        }

           for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                stk2.push(t[i]);
            }
            else if(!stk2.empty()){
                stk2.pop();
            }
        }
        return stk1==stk2;
    }
};