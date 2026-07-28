class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        string res;
        int half=n/2;
        int i=0;
        while(i<half){
            res+=s[i];
            i++;
        }
        string temp=res;
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        sort(res.begin(),res.end());
        if(n%2!=0){
            res+=s[i];
            res+=temp;
            return res;
        }
        else{
            res+=temp;
            return res;
        }
    }
};