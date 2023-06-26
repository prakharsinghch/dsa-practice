class Solution {
public:

    bool check(vector<string>& board, int r, int c, int n){
        
       int x=r,y=c;
        while(y>=0){
            if(board[x][y] =='Q' ) return false;
            y--;
        }
        y=c;
        while(x>= 0  && y >= 0){
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        x= r;
        y=c;
        while(x < n && y>=0){
            if(board[x][y] == 'Q') return false;
            x++;
            y--;
        }
        return true;
    }

    void recr(int n,vector<vector<string>>& grid,vector<string>& board, int c)   {
      if(c  ==  n)
        {
            grid.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(check(board,r,c,n)){
                board[r][c] = 'Q';
                recr(n,grid,board,c+1);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> grid;
        vector<string> row(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            row[i] = s;
        }
        recr(n,grid,row,0);
       
        return grid;
    }
};