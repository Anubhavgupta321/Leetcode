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
    void solve(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int> v){
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum==root->val) ans.push_back(v);
        }
        solve(root->left,targetSum-root->val,ans,v);
        solve(root->right,targetSum-root->val,ans,v);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> v;
        solve(root,targetSum,ans,v);
        return ans;
    }
};