class Solution {
public:

    void recr(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] == 1 || grid[i][j] == '0' ) return;

        vis[i][j] = 1;
        recr(grid,vis,i-1,j);
        recr(grid,vis,i+1,j);
        recr(grid,vis,i,j-1);
        recr(grid,vis,i,j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0 ){
                    ans++;
                    recr(grid,vis,i,j);
                } 
            }
        }

        return ans;
    }
};