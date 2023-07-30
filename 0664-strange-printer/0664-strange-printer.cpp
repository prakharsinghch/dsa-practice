class Solution {
public:

    int recr(string s, int i, int j, vector<vector<int>>& dp){
        if( i== j)  return 1;
        if(dp[i][j]!= -1) return dp[i][j];
        int ans;
        if(s[i] == s[j] || s[j-1] == s[j]) ans =  recr(s,i,j-1,dp);
        else if(s[i] == s[i+1]) ans =  recr(s,i+1,j,dp);
        else{
            ans = recr(s,i,j-1,dp)+1;
            for(int k = i+1;k<j;k++){
                if(s[j] == s[k]){
                    ans = min(recr(s,i,k-1,dp) + recr(s,k,j-1,dp), ans);
                }
            }
        }  
        return dp[i][j] = ans; 
    }

    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return recr(s,0,s.size()-1,dp);
    }
};