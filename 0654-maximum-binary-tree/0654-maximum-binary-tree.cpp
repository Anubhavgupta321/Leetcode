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
    TreeNode* solve(vector<int>& nums,int s,int e){
        if(s>e) return nullptr;
        int idx=s;
        int maxi=nums[s];
        for(int i=s;i<=e;i++){
            if(nums[i]>nums[idx]){
                maxi=nums[i];
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(maxi);
        root->left=solve(nums,s,idx-1);
        root->right=solve(nums,idx+1,e);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};