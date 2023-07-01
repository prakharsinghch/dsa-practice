class Solution {
public:

    int recr(string s, string t, vector<vector<int>>& dp, int i, int j){
        if(j<=0) return 1;
        if(i<=0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // int take=0;
        // if(s[i-1] == t[j-1]) take = recr(s,t,dp,i-1,j-1);
        // int  no_take = recr(s,t,dp,i-1,j);

        // return dp[i][j] = no_take + take;

        if(s[i-1] == t[j-1] ) return dp[i][j] = recr(s,t,dp,i-1,j-1) + recr(s,t,dp,i-1,j);
        return dp[i][j] = recr(s,t,dp,i-1,j);
    }

    int numDistinct(string s, string t) {

        if(s.size() == 0) return 0;
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1,-1));
        return recr(s,t,dp,s.size(),t.size());
    }
};