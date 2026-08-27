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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        vector<vector<int>> ans;
        if(!root) return ans;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto data=q.front();
                q.pop();
                TreeNode* node=data.first;
                int hr=data.second.first;
                int lvl=data.second.second;
                mpp[hr][lvl].push_back(node->val);
                if(node->left) q.push(make_pair(node->left,make_pair(hr-1,lvl+1)));
                if(node->right) q.push(make_pair(node->right,make_pair(hr+1,lvl+1)));
            }
        }
        for(auto hr_lines:mpp){
            vector<int> all_lvls;
            for(auto lvl_lines:hr_lines.second){
                sort(lvl_lines.second.begin(),lvl_lines.second.end());
                all_lvls.insert(all_lvls.end(),lvl_lines.second.begin(),lvl_lines.second.end());
            }
            ans.push_back(all_lvls);
        }
        return ans;
    }
};