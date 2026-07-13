class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int minlen=INT_MAX;
        vector<int> v(256,0);
        for(int i=0;i<m;i++){
            v[t[i]]++;
        }
        int l=0,r=0;
        int cnt=0;
        int strtidx=-1;
        while(r<n){
            if(v[s[r]]>0) cnt++;
            v[s[r]]--;
            while(l<=r && cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    strtidx=l;
                }
                v[s[l]]++;
                if(v[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return minlen==INT_MAX?"":s.substr(strtidx,minlen);
    }
};