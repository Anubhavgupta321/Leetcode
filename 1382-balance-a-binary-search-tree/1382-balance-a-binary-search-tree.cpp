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
    void fill(TreeNode* root,vector<int>& v){
        if(!root) return;
        fill(root->left,v);
        v.push_back(root->val);
        fill(root->right,v);
    }
    TreeNode* insert(vector<int>& v,int lo,int hi){
        int n=v.size();
        if(lo>hi) return nullptr;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=insert(v,lo,mid-1);
        root->right=insert(v,mid+1,hi);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> v;
        fill(root,v);
        return insert(v,0,v.size()-1);
    }
};