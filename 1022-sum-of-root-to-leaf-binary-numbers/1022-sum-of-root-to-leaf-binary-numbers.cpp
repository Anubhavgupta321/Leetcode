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
    void solve(TreeNode* root,int& sum,int num){
        if(!root) return;
        num=num*2+root->val;
        if(!root->left && !root->right){
            sum+=num;
            return;
        }
        solve(root->left,sum,num);
        solve(root->right,sum,num);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        solve(root,sum,0);
        return sum;
    }
};