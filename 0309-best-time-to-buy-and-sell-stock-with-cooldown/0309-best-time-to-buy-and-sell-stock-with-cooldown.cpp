class Solution {
public:

    int recr(vector<int>& prices,int x, int i,vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;

        if(dp[i][x] != -1) return dp[i][x];


        int ans1 = recr(prices,x,i+1,dp);
        int ans2 =0;
        if(x){
            ans2 = -prices[i]+recr(prices,0,i+1,dp);
        }
        else{
            ans2 = prices[i]+recr(prices,1,i+2,dp);
        }

        return dp[i][x] = max(ans1,ans2);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        int ans = recr(prices,1,0,dp); 
        return ans;
    }
};