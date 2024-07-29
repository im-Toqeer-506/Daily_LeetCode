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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> myqueue;
        myqueue.push(p);
        myqueue.push(q);
        while (!myqueue.empty()) {
            TreeNode* first = myqueue.front();
            myqueue.pop();
            TreeNode* second = myqueue.front();
            myqueue.pop();
            if (first == NULL && second == NULL)
                continue;
            else if (first == NULL || second == NULL ||
                     first->val != second->val)
                return false;

            myqueue.push(first->left);
            myqueue.push(second->left);
            myqueue.push(first->right);
            myqueue.push(second->right);
        }

        return true;
    }
};