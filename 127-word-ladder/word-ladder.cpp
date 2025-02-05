class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return 0;

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int length = 0;

        while (!q.empty()) {
            int size = q.size();
            length++;

            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                for (int j = 0; j < current.length(); j++) {
                    string temp = current;

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c; 
                        if (temp == endWord)
                            return length + 1;

                        if (st.find(temp) != st.end() &&
                            visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};