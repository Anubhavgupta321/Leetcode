class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        string token="";
        stringstream ss(path);
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token=="" || token==".") continue;
            if(token!="..") st.push(token);
            else if(!st.empty() && token=="..") st.pop();
        }
        string res="";
        if(st.empty()) return "/";
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        return res;
    }
};