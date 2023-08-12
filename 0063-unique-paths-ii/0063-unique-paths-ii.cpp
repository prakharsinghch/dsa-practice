class Solution {
public:

    int recr(int i,int j, vector<vector<int>>& obs,vector<vector<int>>& dp){

        int m = obs.size(), n = obs[0].size();
        if(i >= m || j>=n) return 0;
        if(obs[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1 && j == n-1) return 1;

        return dp[i][j] = recr(i+1,j,obs,dp) + recr(i,j+1,obs,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
       
        int m = obs.size(), n = obs[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recr(0,0,obs,dp);
    }
};