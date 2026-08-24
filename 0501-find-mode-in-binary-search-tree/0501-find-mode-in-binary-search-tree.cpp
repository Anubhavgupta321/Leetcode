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
    void solve(TreeNode* root,vector<int>& ans,int& maxfreq,int& freq,TreeNode*& prev){
        if(!root) return;
        solve(root->left,ans,maxfreq,freq,prev);
        if(!prev){
            freq=1;
        }
        else if(prev->val==root->val) freq++;
        else freq=1;
        if(freq>maxfreq){
            maxfreq=freq;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(freq==maxfreq){
            ans.push_back(root->val);
        }
        prev=root;
        solve(root->right,ans,maxfreq,freq,prev);
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        int maxfreq=0;
        int freq=0;
        vector<int> ans;
        TreeNode* prev=nullptr;
        solve(root,ans,maxfreq,freq,prev);
        return ans;
    }
};