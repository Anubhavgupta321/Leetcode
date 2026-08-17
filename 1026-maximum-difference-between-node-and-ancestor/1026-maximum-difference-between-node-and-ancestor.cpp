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
    void solve(TreeNode* root,int mini,int maxi,int& ans){
        if(!root) return;
        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        solve(root->left,mini,maxi,ans);
        solve(root->right,mini,maxi,ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,root->val,root->val,ans);
        return ans;
    }
};