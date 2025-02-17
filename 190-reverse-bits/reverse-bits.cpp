class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int Pow = 31;
        long long res = 0;
        while (n != 0) {
            res += ((n & 1) << Pow);
            Pow--;
            n = n >> 1;
        }
        return res;
    }
};
