class Solution {
public:

    int recr(vector<int>& nums, int n, vector<int>& dp){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = max(nums[n] + recr(nums,n-2,dp) , recr(nums,n-1,dp) );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return recr(nums,nums.size()-1,dp);
    }
};