class Solution {
    bool check(vector<int> freq1,vector<int> freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;
        vector<int> freq1(26,0);
        for(int i=0;i<n;i++){
            freq1[s1[i]-'a']++;
        }
        vector<int> freq2(26,0);
        int j=0;
        while(j<n && j<m){
            freq2[s2[j]-'a']++;
            j++;
        }
        if(check(freq1,freq2)) return true;
        int left=0;
        for(int i=n;i<m;i++){
            freq2[s2[left]-'a']--;
            freq2[s2[i]-'a']++;
            left++;
            if(check(freq1,freq2)) return true;
        }
        return false;
    }
};