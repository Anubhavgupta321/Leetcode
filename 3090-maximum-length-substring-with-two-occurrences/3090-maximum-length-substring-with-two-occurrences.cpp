class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int len=0;
        unordered_map<char,int> mpp;
        int l=0,r=0;
        while(r<n){
            mpp[s[r]]++;
            while(l<=r && mpp[s[r]]>2){
                mpp[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};