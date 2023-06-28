class Solution {
public:

    int recr(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int c = nums[ind]*nums[i-1]*nums[j+1] + recr(i,ind-1,nums,dp) + recr(ind+1,j,nums,dp);
            ans = max(c,ans);
        }


        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {   
        int n = nums.size();
        nums.push_back(1);
        nums.insert(begin(nums),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recr(1,n,nums,dp);
    }
};