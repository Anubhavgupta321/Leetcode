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
    void mapping(vector<int>& postorder,unordered_map<int,int>& mpp){
        int n=postorder.size();
        for(int i=0;i<n;i++){
            mpp[postorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,unordered_map<int,int>& mpp,int& preidx,int posts,int poste,int n){
        if(preidx>=n || posts>poste) return nullptr;
        int element=preorder[preidx++];
        TreeNode* root=new TreeNode(element);
        if(posts==poste) return root;
        int nextele=preorder[preidx];
        int pos=mpp[nextele];
        root->left=solve(preorder,postorder,mpp,preidx,posts,pos,n);
        root->right=solve(preorder,postorder,mpp,preidx,pos+1,poste-1,n);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int> mpp;
        mapping(postorder,mpp);
        int preidx=0;
        return solve(preorder,postorder,mpp,preidx,0,n-1,n);
    }
};