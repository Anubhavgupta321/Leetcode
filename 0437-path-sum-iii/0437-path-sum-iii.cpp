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
    void solve(TreeNode* root,long long targetSum,int& cnt){
        if(!root) return;
        if((long long)root->val==targetSum) cnt++;
        solve(root->left,targetSum-(long long)root->val,cnt);
        solve(root->right,targetSum-(long long)root->val,cnt);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int cnt=0;
        solve(root,(long long)targetSum,cnt);
        cnt+=pathSum(root->left,(long long)targetSum)+ pathSum(root->right,(long long)targetSum);
        return cnt;
    }
};