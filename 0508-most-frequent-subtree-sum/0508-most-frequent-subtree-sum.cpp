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
    int solve(TreeNode* root,unordered_map<int,int>& mpp){
        if(!root) return 0;
        int left=solve(root->left,mpp);
        int right=solve(root->right,mpp);
        int sum=left + right + root->val;
        mpp[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        unordered_map<int,int> mpp;
        solve(root,mpp);
        int cnt=0;
        for(auto x:mpp){
            cnt=max(cnt,x.second);
        }
        for(auto x:mpp){
            if(x.second==cnt) ans.push_back(x.first);
        }
        return ans;
    }
};