class Solution {
public:

    int recr(vector<int>& rods, int i, int sum, vector<vector<int>>& dp){
        if(i==rods.size()) {
            if(sum == 5000) return 0;
            return INT_MIN;
        }


        if(dp[i][sum] != INT_MIN) return dp[i][sum];

        int take = recr(rods,i+1,sum+rods[i],dp) + rods[i];
        int give = recr(rods,i+1,sum-rods[i],dp);
        int skip = recr(rods,i+1,sum,dp);

        return dp[i][sum]  = max(max(take,give),skip);
    }

    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(rods.size()+1, vector<int>(10001,INT_MIN));
        return recr(rods,0,5000,dp);
    }
};