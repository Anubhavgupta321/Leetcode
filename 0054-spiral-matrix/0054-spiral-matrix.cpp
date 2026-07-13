class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        vector<int> ans;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                int ele=matrix[top][i];
                ans.push_back(ele);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                int ele=matrix[i][right];
                ans.push_back(ele);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    int ele=matrix[bottom][i];
                    ans.push_back(ele);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    int ele=matrix[i][left];
                    ans.push_back(ele);
                }
                left++;
            }
        }
        return ans;
    }
};