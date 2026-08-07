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
    static const int mod=1e9+7;
    long long get(TreeNode* root){
        if(!root) return 0;
        return root->val + get(root->left) + get(root->right);
    }
    long long solve(TreeNode* root,long long totalsum,long long& ans){
        if(!root) return 0; 
        long long left=solve(root->left,totalsum,ans);
        long long right=solve(root->right,totalsum,ans);
        long long sum=root->val+left+right;
        ans=max(ans,sum*(totalsum-sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        long long totalsum=get(root);
        long long ans=INT_MIN;
        solve(root,totalsum,ans);
        return ans%mod;
    }
};