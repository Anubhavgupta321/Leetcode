class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        int l=s.length();
        long long sum=0;
        long long num=0;
        for(int i=0;i<l;i++){
            if(s[i]!='0'){
                sum+=(s[i]-'0');
                num=num*10+(s[i]-'0');
            }
        }
        return num*sum;
    }
};