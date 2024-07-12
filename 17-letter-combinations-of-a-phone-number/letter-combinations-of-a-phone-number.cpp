class Solution {
public:
 vector<string> map = {
            "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
    void backtrack(vector<string>& result, string current, const string& digits,int index) {
        if (current.length() == digits.length()) {
            result.push_back(current);
            return;
        }
        string digitLetters = map[digits[index] - '0'];
         for (char ch: digitLetters) {
            backtrack(result, current + ch, digits, index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> result;
        backtrack(result, "", digits, 0);
        return result;
    }
};