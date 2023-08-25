class Solution {
public:

    bool recr(string s1, string s2, string s3, int i, int j, int k,vector<vector<int>>& dp){
        if(k == s3.size() && i == s1.size() && j == s2.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(i < s1.size() && s1[i] == s3[k] && j< s2.size() && s2[j] == s3[k]){
            return dp[i][j] = (recr(s1,s2,s3,i+1,j,k+1,dp) || recr(s1,s2,s3,i,j+1,k+1,dp));
        }

        else if(i < s1.size() && s1[i] == s3[k]){
            return dp[i][j] = (recr(s1,s2,s3,i+1,j,k+1,dp));
        }

        else if(j < s2.size() && s2[j] == s3[k]){
            return dp[i][j] = recr(s1,s2,s3,i,j+1,k+1,dp);
        }


        return false;

    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        return recr(s1,s2,s3,0,0,0,dp);
    }
};