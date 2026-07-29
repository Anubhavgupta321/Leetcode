class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        string s="";
        int cnt=0;
        while(s.length()<m){
            s+=a;
            cnt++;
        }
        if(s.find(b)!=string::npos) return cnt;
        s+=a;
        if(s.find(b)!=string::npos) return cnt+1;
        return -1;
    }
};