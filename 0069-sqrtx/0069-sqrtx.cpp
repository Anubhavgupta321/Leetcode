class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long s=1;
        long long e=x;
        long long ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid<=x/mid){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        } 
        return ans;
    }
};