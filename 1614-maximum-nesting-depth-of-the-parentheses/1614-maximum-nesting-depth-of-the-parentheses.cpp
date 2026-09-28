class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]==')') st.pop();
            int sz=st.size();
            ans=max(ans,sz);
        }
        return ans;
    }
};