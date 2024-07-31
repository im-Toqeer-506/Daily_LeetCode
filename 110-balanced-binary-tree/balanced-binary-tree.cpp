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
      int Traverse(TreeNode* root, bool &flag) {
        if (root == NULL)
            return 0;
        int leftH = Traverse(root->left, flag);
        int rightH = Traverse(root->right, flag);
        if (abs(leftH - rightH) > 1)
            flag = false;
        return (max(leftH, rightH) + 1);
    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        Traverse(root,flag);
        return flag;
    }
};