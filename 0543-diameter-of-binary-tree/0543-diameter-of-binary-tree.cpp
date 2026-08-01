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
    int find(TreeNode* root){
        if(!root) return 0;
        return 1+max(find(root->left),find(root->right));
    }
    void solve(TreeNode* root,int& ans){
        if(!root) return;
        int leftht=find(root->left);
        int rightht=find(root->right);
        ans=max(ans,leftht+rightht);
        solve(root->left,ans);
        solve(root->right,ans);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        solve(root,ans);
        return ans;
    }
};