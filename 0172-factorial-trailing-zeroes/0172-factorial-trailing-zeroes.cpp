class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int temp=5;
        int cnt=0;
        while(n>=temp){
            cnt+=n/temp;
            temp=temp*5;
        }
        return cnt;
    }
};