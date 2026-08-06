class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            int num=i;
            int ans=num;
            int prod=1;
            while(num>0){
                int digit=num%10;
                prod=prod*digit;
                num=num/10;
            }
            if(prod%t==0) return ans;
        }
        return -1;
    }
};