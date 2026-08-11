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
    void solve(TreeNode* root,long long& mini,long long& secmin){
        if(!root) return ;
        if(root->val>mini && root->val<secmin){
            secmin=root->val;
        }
        if(root->val<mini){
            secmin=mini;
            mini=root->val;
        }
        solve(root->left,mini,secmin);
        solve(root->right,mini,secmin);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long mini=LLONG_MAX;
        long long secmin=LLONG_MAX;
        solve(root,mini,secmin);
        return secmin==LLONG_MAX?-1:secmin;
    }
};