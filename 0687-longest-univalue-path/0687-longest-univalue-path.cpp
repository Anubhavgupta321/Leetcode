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
    int solve(TreeNode* root,int& ans){
        if(!root) return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int leftans=0,rightans=0;
        if(root->left && root->left->val==root->val) leftans=left+1;
        if(root->right && root->right->val==root->val) rightans=right+1;
        ans=max(ans,leftans+rightans);
        return max(leftans,rightans);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        solve(root,ans);
        return ans;
    }
};