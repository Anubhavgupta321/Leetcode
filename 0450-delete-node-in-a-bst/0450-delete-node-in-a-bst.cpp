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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            if(!root->left && !root->right) return nullptr;
            else if(!root->left || !root->right){
                if(root->left) return root->left;
                return root->right;
            }
            else{
                TreeNode* pred=iop(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else root->right=deleteNode(root->right,key);
        return root;
    }
};