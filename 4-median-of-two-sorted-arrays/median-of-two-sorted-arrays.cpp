class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        
        vector<int> vec;
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                vec.push_back(nums1[i++]);
            } else {
                vec.push_back(nums2[j++]);
            }
        }
        
      
        while (i < m) {
            vec.push_back(nums1[i++]);
        }
        while (j < n) {
            vec.push_back(nums2[j++]);
        }
        
        
        int t = m + n;
        if (t % 2 == 1) {
            return double(vec[t / 2]);
        } else {
            double med = (vec[t / 2] + vec[t / 2 - 1]) / 2.0;
            return med;
        }
    }
};
