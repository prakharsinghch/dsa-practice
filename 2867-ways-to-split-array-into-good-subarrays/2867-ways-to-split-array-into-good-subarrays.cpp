class Solution {
public:

    int m = 1e9+7;

    int recr(vector<int>& nums, vector<vector<int>>& dp, int i, int count){
        if(i == nums.size()) 
        {
            if(count == 1) return 1;
            return 0;
        }
        if(nums[i] ==1) count++;
        if(count>1) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int ans =0;
        if(count ==1){
            ans = recr(nums,dp,i+1,0);
        }
        ans = (ans+recr(nums,dp, i+1, count))%m;
        return dp[i][count] = ans;
            

    }

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2,-1));
        return recr(nums,dp,0,0);
    }
};