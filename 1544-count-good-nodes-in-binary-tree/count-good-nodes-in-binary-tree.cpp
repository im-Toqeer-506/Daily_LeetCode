/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
     int countGoodeNodes(TreeNode* root,int maxVal){
        if(!root)return 0;
        int count=0;
        if(root->val>=maxVal){
            maxVal=root->val;
            count++;
        }
        count+=countGoodeNodes(root->left,maxVal);
        count+=countGoodeNodes(root->right,maxVal);
        return count;
     }
    int goodNodes(TreeNode* root) {
        return countGoodeNodes(root,INT_MIN);
    }
};