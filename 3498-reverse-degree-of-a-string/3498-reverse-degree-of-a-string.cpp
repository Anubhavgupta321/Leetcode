class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            int x=abs(c-'z'-1);
            ans+=(x*(i+1));
        }
        return ans;
    }
};