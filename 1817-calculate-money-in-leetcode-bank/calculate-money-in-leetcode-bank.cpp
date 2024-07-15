class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        int mymoney = 1;
        
        while (n > 0) {
            int money = mymoney;
            for (int i = 0; i <min(n, 7); i++) {
                result += money;
                money++;
            }
            n -= 7;
            mymoney += 1;
        }
        
        return result;
    }
};
