class Solution {
public:

    int recr(vector<int>& prices, int fee, int i, int x,vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;

        if(dp[i][x] != -1) return dp[i][x];

        int leave = recr(prices,fee,i+1,x,dp);
        int sell = 0;
        if(x){
            sell = -prices[i]+recr(prices,fee,i+1,0,dp);
        }else{
            sell = prices[i]-fee+recr(prices,fee,i+1,1,dp);
        }
        return dp[i][x] = max(leave,sell);
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,-1));
        return recr(prices,fee,0,1,dp);
    }
};