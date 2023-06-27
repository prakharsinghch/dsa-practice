class Solution {
public:

    int recr(vector<int>& cost,int n,vector<int>&dp ){
        if(n<=1) return cost[n];
        if(dp[n] != -1) return dp[n];
        int take = recr(cost,n-1,dp);
        int not_take = recr(cost,n-2,dp);

        return dp[n] = cost[n] + min(take,not_take);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min( recr(cost,n-1,dp), recr(cost,n-2,dp) );
    }
};