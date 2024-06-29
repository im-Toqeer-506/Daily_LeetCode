class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        stack<int> stk;
        queue<int> que;

        reverse(sandwiches.begin(), sandwiches.end());
        for (auto sandwi : sandwiches) {
            stk.push(sandwi);
        }
        for (auto talib : students) {
            que.push(talib);
        }
        while (!stk.empty() || !que.empty()) {
            if (stk.top() == que.front()) {

                stk.pop();
                que.pop();
                count = 0;
            } else {
                que.push(que.front());
                que.pop();
                count++;
            }
            if (count >= que.size()) {
                break;
            }
        }
        return que.size();
    }
};