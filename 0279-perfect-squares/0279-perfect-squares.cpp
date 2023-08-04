class Solution {
public:

    int recr(int n, int i,vector<int>& dp){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int take;
        if(i*i<=n) 
        {
            take = 1 + recr(n-i*i, i,dp);
            int notake = recr(n,i+1,dp);
            return dp[n] =min(take,notake);

        }
       
       return 1e6;


    }

    int numSquares(int n) {
        
        vector<int> dp(n+1,-1);
        return recr(n,1,dp);
    }
};