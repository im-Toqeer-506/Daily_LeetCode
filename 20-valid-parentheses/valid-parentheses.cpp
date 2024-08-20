class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;  
        char c;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                Stack.push(s[i]);
            } 
            else {
                if (Stack.empty())
                    return false;
                c = Stack.top(); 
                Stack.pop();
                if ((s[i] == '}' && c != '{') || 
                    (s[i] == ')' && c != '(') || 
                    (s[i] == ']' && c != '[')) {
                    return false;
                }
            }
        }
        return Stack.empty();
    }
};
