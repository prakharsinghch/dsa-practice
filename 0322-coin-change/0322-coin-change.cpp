class Solution {
public:

    int recr(vector<int>& coins,int amount, int i,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(i >= coins.size() || amount < 0 ) return INT_MAX-1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int len = 0 ;
        int take=0,notake = recr(coins,amount,i+1,dp);
        len = notake;
        if(coins[i] <= amount) {
            take = 1+recr(coins,amount-coins[i],i,dp);
            len = min(take,notake);
        }
        return dp[i][amount] = len;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int x = recr(coins,amount,0,dp);
        if(x == INT_MAX-1) return -1;
        return x;
    }
};