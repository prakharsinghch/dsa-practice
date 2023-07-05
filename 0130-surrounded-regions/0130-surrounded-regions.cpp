class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1 )
                {
                    if(board[i][j] == 'O')
                    {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }

            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int row = r + delrow[i];
                int col = c + delcol[i];
               
                if(row >= 0 && col >= 0 && row < n && col < m && !vis[row][col] && board[row][col] == 'O')
                {
                    q.push({row,col});
                    vis[row][col] = 1;
                }
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                     board[i][j] = 'X';
                }
            }
            
        }
       
    }
};