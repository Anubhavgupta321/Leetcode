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
    void preorder(TreeNode* root,string& s){
        if(!root) return;
        s+=to_string(root->val)+",";
        preorder(root->left,s);
        preorder(root->right,s);
    }

    TreeNode* build(vector<int>& v,int& i,long long lo,long long hi){
        if(i>=v.size()) return nullptr;
        if(v[i]<=lo || v[i]>=hi) return nullptr;
        TreeNode* root=new TreeNode(v[i]);
        i++;
        root->left=build(v,i,lo,root->val);
        root->right=build(v,i,root->val,hi);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        preorder(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.length();
        if(n==0) return nullptr;
        string temp;
        vector<int> v;
        for(char c:data){
            if(c==','){
                v.push_back(stoi(temp));
                temp.clear();
            }
            else temp+=c;
        }
        int i=0;
        return build(v,i,LLONG_MIN,LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;