class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<unordered_set<char>> row(9),col(9),boxes(9);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c=board[i][j];
                if(c=='.') continue;
                int boxidx=(i/3)*3+(j/3);
                if(row[i].count(c) || col[j].count(c) || boxes[boxidx].count(c)) return false;
                row[i].insert(c);
                col[j].insert(c);
                boxes[boxidx].insert(c);
            }
        }
        return true;
    }
};