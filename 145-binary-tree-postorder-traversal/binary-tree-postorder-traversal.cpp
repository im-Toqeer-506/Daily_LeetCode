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
    void PostOrder(TreeNode* root, vector<int> &torender) {
        if (root != NULL) {
            PostOrder(root->left,torender);
            PostOrder(root->right,torender);
            torender.push_back(root->val);
        }
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> torender;
    PostOrder(root,torender);
    return torender;
    }
};