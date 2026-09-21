class Solution {
    void insert(vector<int>& ans,int row){
        long long val=1;
        ans.push_back(1);
        for(int col=1;col<row;col++){
            val=val*(row-col);
            val=val/col;
            ans.push_back(val);
        }
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        insert(ans,rowIndex+1);
        return ans;
    }
};