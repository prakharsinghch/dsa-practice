class Solution {
public:

    int recr(int sum,vector<int>& nums, int target,int curr,int i,vector<vector<int>>& dp){
        if(i == nums.size() ) {
            if(curr == target) return 1;
            return 0;
        }

        if(dp[i][sum+curr] != -1) return dp[i][sum+curr];



        int add = recr(sum,nums, target,curr+nums[i], i+1,dp);
        int sub = recr(sum,nums,target,curr-nums[i],i+1,dp);

        return dp[i][sum+curr] = add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(auto x: nums) sum+=x;

        vector<vector<int>> dp(nums.size()+1, vector<int>(2*sum+1,-1));

        if(target>sum||target<-sum){
            return 0;
        }
        return recr(sum,nums,target,0,0,dp);
    }
};