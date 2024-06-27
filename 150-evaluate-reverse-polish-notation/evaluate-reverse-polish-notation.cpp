class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st1;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
                tokens[i] != "/") {
                st1.push(stoi(tokens[i]));
            } else {
                int operand1 = st1.top();
                st1.pop();
                int operand2 = st1.top();
                st1.pop();
                int result;
                if (tokens[i] == "+") {
                    result = operand2 + operand1;
                } else if (tokens[i] == "-") {
                    result = operand2 - operand1;
                } else if (tokens[i] == "*") {
                    result = operand2 * operand1;
                } else if (tokens[i] == "/") {
                  result = operand2 / operand1; 
                }

                st1.push(result);
            }
        }
        return st1.top();
    }
};


