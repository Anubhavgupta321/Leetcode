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
    void solve(TreeNode* root,TreeNode*& prev,int& ans){
        if(!root) return;
        solve(root->left,prev,ans);
        if(prev){
            ans=min(ans,abs(root->val-prev->val));
        }
        prev=root;
        solve(root->right,prev,ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        TreeNode* prev=nullptr;
        solve(root,prev,ans);
        return ans;
    }
};