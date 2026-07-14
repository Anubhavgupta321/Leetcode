class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> ptos;
        unordered_map<string,char> stop;
        int j=0,k=0;
        int n=s.length();
        for(int i=0;i<pattern.length();i++){
            if(j>=n) return false;
            char c=pattern[i];
            while(j<n && s[j]!=' '){
                j++;
            }
            string w=s.substr(k,j-k);
            if(ptos.count(c) && ptos[c]!=w) return false;
            if(stop.count(w) && stop[w]!=c) return false;
            ptos[c]=w;
            stop[w]=c;
            if(j<n){
                k=j+1;
                j++;
            }
        }
        if(j<n) return false;
        return true;
    }
};