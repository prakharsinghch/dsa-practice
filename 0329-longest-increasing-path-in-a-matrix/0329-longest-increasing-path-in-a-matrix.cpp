class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, int n , int m, vector<vector<int>>& mtx,int pre)
    {
        if(i>=n || j>=m || i<0 || j<0 || mtx[i][j] <= pre)
            return 0;
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int p = dfs(i-1,j,n,m,mtx,mtx[i][j]);
        int q = dfs(i+1,j,n,m,mtx,mtx[i][j]);
        int r = dfs(i,j-1,n,m,mtx,mtx[i][j]);
        int s = dfs(i,j+1,n,m,mtx,mtx[i][j]);
        int ans = max({p,q,r,s})+1;
        return dp[i][j] = ans;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& mtx) {
        
        int n = mtx.size();
        if(n == 0)
            return n;
        int m = mtx[0].size();
        
        int res = 0;
        dp.resize(201,vector<int>(201,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res = max(res,dfs(i,j,n,m,mtx,-1));
            }
        }
        return res;             
    }
};