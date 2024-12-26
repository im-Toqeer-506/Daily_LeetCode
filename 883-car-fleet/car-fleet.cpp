class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<float> st;
        vector<pair<int, float>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({position[i], float(target - position[i]) / speed[i]});
        }

        sort(vec.begin(), vec.end());
        for (auto i : vec) {
            float t = i.second;
            while (st.size() && (t >= st.top()))
                st.pop();
            st.push(t);
        }

        return st.size();
    }
};
