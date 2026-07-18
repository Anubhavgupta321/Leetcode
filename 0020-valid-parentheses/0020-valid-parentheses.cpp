class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{') st.push(c);
            else{
                if(st.empty()) return false;
                if(c==')'){
                    if(st.top()!='(') return false;
                    st.pop();
                }
                else if(c==']'){
                    if(st.top()!='[') return false;
                    st.pop();
                }
                else{
                    if(st.top()!='{') return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};