class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        int cnt=1;
        long long start=1000;
        while(start<=n){
            long long end=min(n, start*1000-1);
            ans+=(end-start+1)*cnt;
            start*=1000;
            cnt++;
        }
        return ans;
    }
};