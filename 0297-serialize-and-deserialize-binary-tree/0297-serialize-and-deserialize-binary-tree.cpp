/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        string data="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node){
                data+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                data+="#,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#,") return nullptr;
        string d;
        stringstream ss(data);
        getline(ss,d,',');
        TreeNode* root=new TreeNode(stoi(d));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(ss,d,',');
            if(d!="#"){
                node->left=new TreeNode(stoi(d));
                q.push(node->left);
            }
            else node->left=nullptr;
            getline(ss,d,',');
            if(d!="#"){
                node->right=new TreeNode(stoi(d));
                q.push(node->right);
            }
            else node->right=nullptr;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));