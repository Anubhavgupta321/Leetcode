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
    bool solve(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(root && !subRoot) return false;
        if(!root && subRoot) return false;
        bool val=root->val==subRoot->val;
        bool left=solve(root->left,subRoot->left);
        bool right=solve(root->right,subRoot->right);
        return val && left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot) return false;
        if(solve(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};