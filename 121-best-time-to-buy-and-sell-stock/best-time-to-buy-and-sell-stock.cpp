class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int b = prices[0];
        int s = 0;
        for (auto price : prices) {
            if (price < b) {
                b = price;
            } else if (price - b > s) {
                s = price - b;
            }
        }

        return s;
    }
};