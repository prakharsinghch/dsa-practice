class Solution {
public:

bool issafe(vector<vector<char>>& board,int row,int col,int dig){

    for(int i=0;i<9;i++){
        if(board[row][i]==dig){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(board[j][col]==dig){
            return false;
        }
    }
    int currRow=(row/3)*3;
    int currCol=(col/3)*3;

    for(int i=currRow;i<currRow+3;i++){
        for(int j=currCol;j<currCol+3;j++){
            if(board[i][j]==dig){
                return false;
            }

        }

    }
    return true;

}
bool sodukuhelper(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char dig='1';dig<='9';dig++){
                    if(issafe(board,i,j,dig)){
                        board[i][j]=dig;
                       if(sodukuhelper(board)){
                        return true;
                       }
                       board[i][j]='.';
                    }

                }
                return false;
            }

        }

    }
    return true;
}


    void solveSudoku(vector<vector<char>>& board) {

        sodukuhelper(board);
    }
};