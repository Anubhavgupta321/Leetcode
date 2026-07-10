class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int len=0;
        unordered_map<char,int> mpp;
        int left=0;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            while(left<=right && mpp[s[right]]>1){
                mpp[s[left]]--;
                left++;
            }
            len=max(len,right-left+1);
        }
        return len;
    }
};