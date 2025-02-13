class Solution {
public:
//Just only understand how xor OPerator works 
//0 xor 0 =>0
//1 xor 1=>0
//1 xor 0=>1
//0 xor 1=>1
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto num:nums)
        {
         result^=num;
        }
        return result;
    }
};
