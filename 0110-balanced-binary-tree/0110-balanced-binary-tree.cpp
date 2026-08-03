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
    pair<bool,int> solve(TreeNode* root){
        if(!root) return {true,0};
        pair<bool,int> leftans=solve(root->left);
        pair<bool,int> rightans=solve(root->right);
        bool l=leftans.first;
        bool r=rightans.first;
        bool ht=abs(leftans.second-rightans.second)<=1;
        pair<bool,int> ans;
        if(l && r && ht) ans.first=true;
        else ans.first=false;
        ans.second=max(leftans.second,rightans.second)+1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};