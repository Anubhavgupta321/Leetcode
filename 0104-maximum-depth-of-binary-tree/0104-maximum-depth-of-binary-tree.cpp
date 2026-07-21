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
    void solve(TreeNode* root,int height,int& maxheight){
        if(!root) return;
        if(!root->left && !root->right){
            maxheight=max(maxheight,height);
            return;
        }
        solve(root->left,height+1,maxheight);
        solve(root->right,height+1,maxheight);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxheight=INT_MIN;
        solve(root,1,maxheight);
        return maxheight;
    }
};