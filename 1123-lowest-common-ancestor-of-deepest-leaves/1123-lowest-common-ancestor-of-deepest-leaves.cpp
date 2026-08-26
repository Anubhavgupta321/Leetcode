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
    pair<int, TreeNode*> solve(TreeNode* root){
        if(!root) return {0,nullptr};
        pair<int,TreeNode*> left=solve(root->left); 
        pair<int,TreeNode*> right=solve(root->right);
        int leftht=left.first;
        int rightht=right.first;
        if(leftht>rightht){
            return {leftht+1,left.second};
        }
        else if(rightht>leftht){
            return {rightht+1,right.second};
        }
        else return {leftht+1,root};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};