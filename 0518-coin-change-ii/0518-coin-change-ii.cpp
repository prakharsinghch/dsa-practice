class Solution {
public:
    int ans=0;
    int recr(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(i>=coins.size() || amount<0) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1 ) return dp[i][amount];
        int take = recr(i,amount-coins[i],coins,dp);
        int not_take;
        if(i<coins.size()) not_take = recr(i+1,amount,coins,dp);

        return  dp[i][amount] = take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
        ans = recr(0,amount, coins,dp);
        return ans;
    }
};