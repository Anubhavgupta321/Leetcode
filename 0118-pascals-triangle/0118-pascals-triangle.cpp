class Solution {
    void insert(vector<vector<int>>& ans,int row){
        vector<int> v;
        long long res=1;
        v.push_back(1);
        for(int col=1;col<row;col++){
            res=res*(row-col);
            res=res/col;
            v.push_back(res);
        }
        ans.push_back(v);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1;row<=numRows;row++){
            insert(ans,row);
        }
        return ans;
    }
};