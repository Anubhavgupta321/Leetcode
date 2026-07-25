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
    int getleftht(TreeNode* root){
        int ans=0;
        TreeNode* temp=root;
        while(temp){
            ans++;
            temp=temp->left;
        }
        return ans;
    }
    int getrightht(TreeNode* root){
        int ans=0;
        TreeNode* temp=root;
        while(temp){
            ans++;
            temp=temp->right;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftht=getleftht(root);
        int rightht=getrightht(root);
        if(leftht==rightht) return (1<<leftht)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};