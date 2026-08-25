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
    void solve(TreeNode* root,TreeNode*& prev){
        if(!root) return;
        solve(root->left,prev);
        prev->right=root;
        root->left=nullptr;
        prev=root;
        solve(root->right,prev);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* dummy=new TreeNode(-1);
        TreeNode* prev=dummy;
        solve(root,prev);
        return dummy->right;
    }
};