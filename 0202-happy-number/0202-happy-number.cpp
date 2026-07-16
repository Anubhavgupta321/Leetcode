class Solution {
    int getnext(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            ans+=digit*digit;
            n=n/10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        // unordered_set<int> seen;
        // while(n!=1 && !seen.count(n)){
        //     seen.insert(n);
        //     n=getnext(n);
        // }
        // return n==1;

        int slow=n;
        int fast=getnext(n);
        while(fast!=1 && fast!=slow){
            slow=getnext(slow);
            fast=getnext(getnext(fast));
        }
        return fast==1;
    }
};