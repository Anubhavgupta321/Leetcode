class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        vector<bool> instack(26,false);
        for(char c:s){
            freq[c-'a']++;
        }
        stack<char> st;
        for(char c:s){
            freq[c-'a']--;
            if(instack[c-'a']) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                instack[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            instack[c-'a']=true;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};