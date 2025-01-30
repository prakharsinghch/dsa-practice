class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int> d0 = {-1,0,1,0};
        vector<int> d1 = {0,1,0,-1};

        int ans =0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nRow = r + d0[i];
                int nCol = c + d1[i];
                if(nRow >=0 && nCol>=0 && nRow < m && nCol < n && vis[nRow][nCol] !=2 && grid[nRow][nCol] == 1){
                    vis[nRow][nCol] = 2;
                    q.push({{nRow,nCol},t+1});
                }
            }
            ans = max(ans,t);
        }



        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<vis[i][j]<<" ";
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
            cout<<endl;
        }    

        return ans;

    }
};