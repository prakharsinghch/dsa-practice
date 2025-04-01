class Solution {
public:

    long long recr(vector<vector<int>>& questions, int i,vector<long long>& dp){
        if(i>= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long take = questions[i][0] + recr(questions,i+questions[i][1]+1,dp);
        long long notake = recr(questions,i+1,dp);
        return dp[i] = max(take,notake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        vector<long long> dp(questions.size(),-1);
        return recr(questions,0,dp);
    }
};