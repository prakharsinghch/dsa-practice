class Solution {
public:

    bool recr(vector<vector<char>>& board, string word, int ind, int r, int c, vector<vector<int>>& vis){
        if(ind == word.size()) return true;

        if(r < 0|| c<0 || r>=board.size() || c>=board[0].size()) return false;

        if(!vis[r][c] && board[r][c] == word[ind]){
            vis[r][c] = 1;
            if(recr(board,word,ind+1,r+1,c,vis) ||
            recr(board,word,ind+1,r-1,c,vis) ||
            recr(board,word,ind+1,r,c+1,vis) ||
            recr(board,word,ind+1,r,c-1,vis)) return true;

        else {
            vis[r][c] = 0;
            return false;
        }        
         
                }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size(), m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bool ans;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              if(board[i][j]==word[0])
                ans=recr(board,word,0,i,j,vis);
                if(ans)
                return ans;
          }
      }
       return ans;
        return recr(board,word,0,0,0,vis);
    }
};