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
//ye tu inorder triversal ho jaye aay ga.....
void Inorder(TreeNode* root, int &k,int &ans){
    if(root==NULL)return ;
    Inorder(root->left,k,ans);
    k--;
    if(k==0)ans=root->val;
    Inorder(root->right,k,ans);
    
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=1;
        Inorder(root,k,ans);
        return ans;
        
    }
};