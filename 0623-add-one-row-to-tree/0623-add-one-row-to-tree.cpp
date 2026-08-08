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
    void solve(TreeNode* root,int val,int depth){
        if(!root) return;
        if(depth==1){
            TreeNode* newleft=new TreeNode(val);
            TreeNode* newright=new TreeNode(val);
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            root->left=newleft;
            root->right=newright;
            newleft->left=left;
            newright->right=right;
            return;
        }
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return nullptr;
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        solve(root,val,depth-1);
        return root;
    }
};