/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& torender) {
        if (root != NULL) {
            InOrder(root->left,torender);
            torender.push_back(root->val);
            InOrder(root->right,torender);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> torender;
        InOrder(root, torender);
        return torender;
    }
};