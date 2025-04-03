class Solution {
public:

    int recr(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        if(i >= grid.size() || j >= grid[0].size()) return 1e8;
        if(dp[i][j] != -1) return dp[i][j];
        int right= grid[i][j] + recr(grid,i,j+1,dp);
        int down = grid[i][j] + recr(grid,i+1,j,dp);

        return dp[i][j] = min(right,down);
        
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recr(grid,0,0,dp);
    }
};