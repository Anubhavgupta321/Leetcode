class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int num=stoi(s);
        int digit1=num%10;
        num=num/10;
        int digit2=num%10;
        return digit1*digit2;
    }
};