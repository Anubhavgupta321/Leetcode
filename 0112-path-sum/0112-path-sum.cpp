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
    void solve(TreeNode* node,int sum,int targetSum,bool& ok){
        if(!node) return;
        sum+=node->val;
        if(!node->left && !node->right){
            if(sum==targetSum) ok=true;
            return;
        }
        solve(node->left,sum,targetSum,ok);
        solve(node->right,sum,targetSum,ok);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=0;
        bool ok=false;
        solve(root,sum,targetSum,ok);
        return ok;
    }
};