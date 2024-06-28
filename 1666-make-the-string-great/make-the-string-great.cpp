class Solution {
public:
    string makeGood(string s) {
      
        string result = "";
        for (auto &c : s) {
           
            if (!result.empty()&&(result.back() == c - 32 || result.back() == c + 32)) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};