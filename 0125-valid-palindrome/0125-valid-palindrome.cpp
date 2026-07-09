class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string temp="";
        for(char c:s){
            if(isalnum(c)){
                temp+=tolower(c);
            }
        }
        int m=temp.length();
        int i=0,j=m-1;
        while(i<=j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};