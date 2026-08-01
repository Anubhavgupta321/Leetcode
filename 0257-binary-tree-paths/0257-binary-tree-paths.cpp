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
    void solve(TreeNode* root,vector<string>& v,string s){
        if(!root) return;
        s+=to_string(root->val);
        if(!root->left && !root->right){
            v.push_back(s);
            return;
        }
        solve(root->left,v,s+"->");
        solve(root->right,v,s+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> v;
        solve(root,v,"");
        return v;
    }
};