class Solution {
public:
    // Array Simulation
    // O(n log n)
    // O(1)
    // Two pointers
    //  O(n)
    // O(n)

    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> vec1(nums.size());

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            if (leftSq > rightSq) {
                vec1[index--] = leftSq;
                left++;
            } else {
                vec1[index--] = rightSq;
                right--;
            }
        }
        return vec1;
    }
};
