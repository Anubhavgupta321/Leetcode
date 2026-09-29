class Solution {
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<char>>& grid,int i,int j,int bal){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m) return false;
        if(grid[i][j]=='(') bal++;
        else bal--;
        if(bal<0) return false;
        if(dp[i][j][bal]!=-1){
            return dp[i][j][bal];
        }
        if(i==n-1 && j==m-1){
            return dp[i][j][bal]=(bal==0);
        }
        return dp[i][j][bal]=dfs(grid,i+1,j,bal) || dfs(grid,i,j+1,bal);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=0;
        if(n+m-1%2==1) return false;
        if(grid[0][0]!='(') return false;
        if(grid[n-1][m-1]!=')') return false;
        int maxbalance=m+n;
        dp.assign(n,vector<vector<int>>(m,vector<int>(maxbalance+1,-1))); 
        return dfs(grid,0,0,0);
    }
};