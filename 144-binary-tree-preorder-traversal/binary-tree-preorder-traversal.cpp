class Solution {
public:
    void PreOrder(TreeNode* root, vector<int>& toreturn) {
        if (root != nullptr) {
            toreturn.push_back(root->val);
            PreOrder(root->left, toreturn);
            PreOrder(root->right, toreturn);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> toreturn;
        PreOrder(root, toreturn);
        return toreturn;
    }
};