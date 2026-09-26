class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        int m=knowledge.size();
        unordered_map<string,string> mpp;
        for(int i=0;i<m;i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    j++;
                }
                string temp=s.substr(i+1,j-i-1);
                if(mpp.count(temp)){
                    s.replace(i,j-i+1,mpp[temp]);
                    i+=mpp[temp].length();
                }
                else{
                    s.replace(i,j-i+1,"?");
                    i++;
                }
            }
            else i++;
        }
        return s;
    }
};