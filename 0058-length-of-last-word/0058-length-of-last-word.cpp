class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        while(i>=0){
            if(isalpha(s[i])){
                int j=i;
                while(i>=0 && s[i]!=' '){
                    i--;
                }
                return j-i;
            }
            i--;
        }
        return -1;
    }
};