class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        int i=0;
        while(i<n){
            if(haystack[i]==needle[0]){
                int j=0;
                int strt=i;
                while(j<m && haystack[i+j]==needle[j]){
                    j++;
                }
                if(j==m) return strt; 
            }
            i++;
        }
        return -1;
    }
};