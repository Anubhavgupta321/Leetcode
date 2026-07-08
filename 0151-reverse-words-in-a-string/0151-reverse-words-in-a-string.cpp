class Solution {
    void reversew(string& s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return;
    }
public:
    string reverseWords(string s) {
        //this solution take extra space as ans string
        // int n=s.length();
        // string ans="";
        // int i=n-1;
        // while(i>=0){
        //     while(i>=0 && s[i]==' ') i--;
        //     if(i<0) break;
        //     int j=i;
        //     while(j>=0 && s[j]!=' '){
        //         j--;
        //     }
        //     ans+=s.substr(j+1,i-j);
        //     ans+=' ';
        //     i=j-1;
        // }
        // ans.pop_back();
        // return ans;

        //O(1) soln , inplace reversal
        int n=s.length();
        //remove extra spaces
        int i=0;
        int j=0;
        while(j<n){
            while(j<n && s[j]==' '){
                j++;
            }
            while(j<n && s[j]!=' '){
                s[i++]=s[j++];
            }
            while(j<n && s[j]==' ') j++;
            if(j<n) s[i++]=' ';
        }
        s.resize(i);
        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=s.size();end++){
            if(end==s.size() || s[end]==' '){
                reversew(s,start,end-1);
                start=end+1;
            }
        }
        return s;
    }
};