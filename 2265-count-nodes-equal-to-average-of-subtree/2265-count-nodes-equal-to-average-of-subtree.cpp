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
    pair<int,int> solve(TreeNode* root,int& cnt){
        if(!root) return {0,0};
        if(!root->left && !root->right){
            cnt++;
            return {root->val,1};
        }
        pair<int,int> left=solve(root->left,cnt);
        pair<int,int> right=solve(root->right,cnt);
        int leftsum=left.first;
        int rightsum=right.first;
        int n=left.second+right.second;
        if((leftsum+rightsum+root->val)/(n+1)==root->val) cnt++;
        return {leftsum+rightsum+root->val,n+1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};