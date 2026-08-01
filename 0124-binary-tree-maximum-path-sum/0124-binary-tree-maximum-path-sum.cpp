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
        int leftans=max(0,solve(root->left,ans));
        int rightans=max(0,solve(root->right,ans));
        ans=max(ans,leftans+rightans+root->val);
        return root->val+max(leftans,rightans);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};