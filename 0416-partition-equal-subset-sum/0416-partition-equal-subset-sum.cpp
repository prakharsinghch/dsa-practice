class Solution {
public:

    bool recr(vector<int>& nums,vector<vector<int>>& dp, int n, int sum){
        if(sum == 0) return true;
        if(n == 0) return  nums[0]==sum;

        if(dp[n][sum] != -1) return dp[n][sum];

        bool not_take = recr(nums,dp,n-1,sum);
        bool take=false;
        if(sum>nums[n]){
            take = recr(nums,dp,n-1,sum-nums[n]);
        }

        return dp[n][sum] = take || not_take;

    }

    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto x: nums) sum+=x;
        if(sum%2) return false;
        else{
            sum=sum/2;
            vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
            return recr(nums, dp,nums.size()-1,sum);
        }
    }
};