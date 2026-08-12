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
    int solve(TreeNode* root,int& moves){
        if(!root) return 0;
        int leftbal=solve(root->left,moves);
        int rightbal=solve(root->right,moves);
        moves+=abs(leftbal)+abs(rightbal);
        int bal=leftbal+rightbal+root->val-1;
        return bal;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};