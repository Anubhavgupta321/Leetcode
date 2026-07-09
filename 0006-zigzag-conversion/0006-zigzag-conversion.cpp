class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1 || numRows>=n) return s;
        vector<string> row(numRows);
        bool goingdown=true;
        int currow=0;
        string ans="";
        for(char c:s){
            row[currow]+=c;
            if(currow==numRows-1){
                goingdown=false;
            }
            else if(currow==0) goingdown=true;
            if(goingdown){
                currow++;
            }
            else currow--;
        }
        for(string s:row){
            ans+=s;
        }
        return ans;
    }
};