class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<pair<int,int>> pairing;
       for(int i = 0; i < numbers.size(); i++) {
           pairing.push_back({numbers[i], i});
       }
       sort(pairing.begin(), pairing.end());
       int left = 0;
       int right = pairing.size() - 1;
       while (left < right) {
           int sum = pairing[left].first + pairing[right].first;
           if (sum == target) {
               return {pairing[left].second, pairing[right].second};
           } else if (sum < target) {
               left++;
           } else {
               right--;
           }
       }
    return {};
    }
};
