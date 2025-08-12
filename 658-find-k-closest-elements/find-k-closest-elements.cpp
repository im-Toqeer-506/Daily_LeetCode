class Solution {
    //hint yahi hai sliding window k lia closet ka word hai 
    //is approch ma ye sorted bhi tu hai
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
    int  left = 0;
    int right = arr.size() - 1;
    vector<int>ans;
    while((right-left+1)>k)
    {
        if(abs(arr[left]-x)>abs(arr[right]-x))
        {
            left++;
        }
        else{
            right--;
        }

        
    }
    for (int i = left; i <= right; i++) {
            ans.push_back(arr[i]);
        }
    return ans;
    }
};