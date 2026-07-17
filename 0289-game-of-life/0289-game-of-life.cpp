class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // int n=board.size();
        // int m=board[0].size();
        // vector<vector<int>> next(n,vector<int>(m));
        // vector<pair<int,int>> dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};//direction vector for all eight direction
        // for(int r=0;r<n;r++){
        //     for(int c=0;c<m;c++){
        //         int val=board[r][c];
        //         int live=0;
        //         for(auto [dr,dc]:dir){
        //             int nr=r+dr;
        //             int nc=c+dc;
        //             if(nr >= 0 && nr < n && nc >= 0 && nc < m){
        //                 int val2=board[nr][nc];
        //                 if(val2==1) live++;
        //             }
        //         }
        //         if(val==1){
        //             if(live<2) next[r][c]=0;
        //             else if(live==2 || live==3) next[r][c]=1;
        //             else next[r][c]=0;
        //         }
        //         else{
        //             if(live==3) next[r][c]=1;
        //             else next[r][c]=0;               
        //         }
        //     }
        // }
        // board=next;

        //doing it inplace without using extra space
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>> dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                int live=0;
                for(auto [dr,dc]:dir){
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int val=board[nr][nc];
                        if(val==1 || val==-1) live++;
                    }
                }
                if(board[r][c]==1){
                    if(live<2 || live>3) board[r][c]=-1;
                }
                else{
                    if(live==3){
                        board[r][c]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2) board[i][j]=1;
                else if(board[i][j]==-1) board[i][j]=0;
            }
        }
    }
};