class Solution {
public:

    bool recr(vector<int>&nums, vector<vector<int>>& dp,int i,int sum){
        if(sum == 0) return true;
        if(i >= nums.size()) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        int take=0,notake = recr(nums,dp,i+1,sum);
        if(sum >= nums[i]) take = recr(nums,dp,i+1,sum-nums[i]);

        return dp[i][sum] = take||notake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum+=x;
        if(sum%2) return false;
        else{
            sum=sum/2;
            vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
            return recr(nums,dp,0,sum);
        }
    }
};