class Solution {
public:

    int recr(vector<int>& nums, int target, int i ,vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int take = 0;

        for(int j = 0 ;j<nums.size();j++){
            take += recr(nums, target-nums[j] , i,dp);
        }


        return dp[target] = take;


    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return recr(nums,target,0,dp);
    }
};