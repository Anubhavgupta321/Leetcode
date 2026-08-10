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
    TreeNode* solve(TreeNode* root){
        if(!root) return nullptr;
        root->left=solve(root->left);
        root->right=solve(root->right);
        int val=root->val;
        if(!root->left && !root->right && val!=1) return nullptr;
        return root;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);
    }
};