class Solution {
public:

    int m = 1e9+7;

    int recr(int n, int x, int i,vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(pow(i,x) > n ) return 0;

        if(dp[n][i] != -1) return dp[n][i];

        long long take = recr(n-pow(i,x), x,i+1,dp);
        long long notake = recr(n,x, i+1,dp);
        
        return dp[n][i] = (take+notake)%m ;
    }

    int numberOfWays(int n, int x) {
        int mx = 1;
        while(pow(mx,x) <= n ) mx++;
        vector<vector<int>> dp(301, vector<int>(mx+1,-1));
        return recr(n,x,1,dp);
    }
};