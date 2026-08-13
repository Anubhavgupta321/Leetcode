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
    void solve(TreeNode* root,int val,int& depth,int& parent,int curr){
        if(!root) return;
        if(!root->left && !root->right) return;
        if((root->left && root->left->val==val) || (root->right && root->right->val==val)){
            depth=curr+1;
            parent=root->val;
            return;
        }
        solve(root->left,val,depth,parent,curr+1);
        solve(root->right,val,depth,parent,curr+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int depthx=0,depthy=0;
        int parentx=-1,parenty=-1;
        solve(root,x,depthx,parentx,0);
        solve(root,y,depthy,parenty,0);
        if(depthx!=depthy) return false;
        if(parentx==parenty) return false;
        return true;
    }
};