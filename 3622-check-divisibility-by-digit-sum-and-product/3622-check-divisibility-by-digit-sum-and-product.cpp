class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,x=n;
        while(x>0){
            sum+=x%10;
            x=x/10;
        }
        x=n;
        int prod=1;
        while(x>0){
            prod*=x%10;
            x=x/10;
        }
        int finalsum=sum+prod;
        if(n%finalsum==0) return true;
        else return false;
    }
};