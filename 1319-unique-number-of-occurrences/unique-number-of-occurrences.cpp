class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> set;
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
            cout<<map[arr[i]]<<" ";
        }
        for (auto it : map) {
            if (set.find(it.second) != set.end()) {
                return false;
            } else {
                set.insert(it.second);
            }
        }
        return true;
    }
};