class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int cnt=1;
        int ans=0;
        while(n>0){
            if(n>8) ans+=cnt*8;
            else ans+=cnt*n;
            cnt++;
            n=n-8;
        }
        return ans;
    }
};