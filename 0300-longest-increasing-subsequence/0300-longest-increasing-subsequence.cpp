class Solution {
public:

    int recr(int i, int prev, vector<int>& nums,vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = 0, dont = recr(i+1,prev,nums,dp);
        if( prev == -1 || nums[i] > nums[prev]) take = 1+recr(i+1,i,nums,dp);
        return dp[i][prev+1] = max(take,dont);
     } 

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return recr(0,-1,nums,dp);
    }
};