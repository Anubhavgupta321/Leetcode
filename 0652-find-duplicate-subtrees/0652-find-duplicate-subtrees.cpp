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
    string solve(TreeNode* root,unordered_map<string,int>& mpp,vector<TreeNode*>& ans){
        if(!root) return "#";
        string left=solve(root->left,mpp,ans);
        string right=solve(root->right,mpp,ans);
        string res=to_string(root->val)+','+left+','+right;
        if(++mpp[res]==2) ans.push_back(root);
        return res;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        unordered_map<string,int> mpp;
        vector<TreeNode*> ans;
        solve(root,mpp,ans);
        return ans;

    }
};