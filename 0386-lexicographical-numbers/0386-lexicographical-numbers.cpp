class Solution {
    void solve(int n,int curr,vector<int>& res){
        if(curr>n) return;
        res.push_back(curr);
        for(int append=0;append<=9;append++){
            int newnum=curr*10+append;
            if(newnum>n) return;
            solve(n,newnum,res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int start=1;start<=9;start++){
            solve(n,start,res);
        }
        return res;
    }
};