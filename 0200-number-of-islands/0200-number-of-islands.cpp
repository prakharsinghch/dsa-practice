class Solution {
public:

    void check(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i< 0 || j<0 || i>=m || j>=n || vis[i][j] == 1 || grid[i][j] == 0){
            return;
        }
        
        

        if(grid[i][j] == '1' && vis[i][j] == 0){
            vis[i][j] = 1;
            check(grid,vis,i+1,j);
            check(grid,vis,i-1,j);
            check(grid,vis,i,j+1);
            check(grid,vis,i,j-1);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    ans++;
                    check(grid,vis,i+1,j);
                    check(grid,vis,i-1,j);
                    check(grid,vis,i,j+1);
                    check(grid,vis,i,j-1);
                }
            }
        }
        return ans;
    }
};