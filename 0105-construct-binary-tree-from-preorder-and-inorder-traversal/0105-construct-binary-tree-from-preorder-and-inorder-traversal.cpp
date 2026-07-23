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
    void mapping(unordered_map<int,int>& nodetoidx,int n,vector<int>& inorder){
        for(int i=0;i<n;i++){
            nodetoidx[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& nodetoidx,int& index,int instart,int inend,int n){
        if(index>=n || instart>inend) return nullptr;
        int ele=preorder[index];
        index++;
        int inidx=nodetoidx[ele];
        TreeNode* root=new TreeNode(ele);
        root->left=solve(preorder,inorder,nodetoidx,index,instart,inidx-1,n);
        root->right=solve(preorder,inorder,nodetoidx,index,inidx+1,inend,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> nodetoidx;
        mapping(nodetoidx,n,inorder);
        int preidx=0;
        return solve(preorder,inorder,nodetoidx,preidx,0,n-1,n);
    }
};