class Solution {
public:


    int recr(vector<int>& nums, int n, vector<int>& dp){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = max(nums[n] + recr(nums,n-2,dp) , recr(nums,n-1,dp) );
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1 ) return nums[0];
        int n = nums.size();
        vector<int> dp(n,-1);
        vector<int> rf = nums;
        rf.erase(rf.begin());
        int a1 = recr(nums,nums.size()-2,dp); 
        vector<int> x(n,-1);
        int a2 = recr(rf, rf.size()-1,x);
        return max(a1,a2) ;
    }
};