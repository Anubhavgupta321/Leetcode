class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int l=strs[0].length();
        string ans="";
        for(int i=0;i<l;i++){
            char c=strs[0][i];
            bool ok=true;
            for(string s:strs){
                if(s[i]!=c){
                    ok=false;
                    break;
                }
            }
            if(ok) ans+=c;
            else break;
        }
        return ans;
    }
};