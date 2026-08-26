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
    int dfs(TreeNode* root,int x,int& leftcnt,int& rightcnt){
        if(!root) return 0;
        int l=dfs(root->left,x,leftcnt,rightcnt);
        int r=dfs(root->right,x,leftcnt,rightcnt);
        if(root->val==x){
            leftcnt=l;
            rightcnt=r;
        }
        return l+r+1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(!root) return true;
        int leftcnt=0,rightcnt=0;
        dfs(root,x,leftcnt,rightcnt);
        int rem=n-(leftcnt+rightcnt+1);
        int maxi=max(rem,max(leftcnt,rightcnt));
        return maxi>n/2;
    }
};