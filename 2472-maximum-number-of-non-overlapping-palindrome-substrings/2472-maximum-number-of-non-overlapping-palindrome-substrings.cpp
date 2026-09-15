class Solution {
    bool ispalin(string s,int l,int e){
        while(l<e){
            if(s[l]!=s[e]) return false;
            l++;
            e--;
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;){
            if(i+k<=n && ispalin(s,i,i+k-1)){
                ans++;
                i+=k;
            }
            else if(i+k+1<=n && ispalin(s,i,i+k)){
                ans++;
                i+=k+1;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};