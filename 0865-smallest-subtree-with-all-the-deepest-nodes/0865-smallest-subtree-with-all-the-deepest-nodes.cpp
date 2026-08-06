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
    int find(TreeNode* root){
        if(!root) return 0;
        return 1+max(find(root->left),find(root->right));
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       if(!root) return nullptr;
       int leftht=find(root->left);
       int rightht=find(root->right);
       if(leftht==rightht) return root;
       if(leftht>rightht) return subtreeWithAllDeepest(root->left);
       return subtreeWithAllDeepest(root->right); 
    }
};