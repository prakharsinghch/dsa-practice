class Solution {
public:

    int recr(string s, int i,vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1) return dp[i];
        int res = recr(s,i+1,dp);
        if(i<s.size()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]< '7') )) res += recr(s,i+2,dp);

        return dp[i] = res;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return s.empty() ? 0 : recr(s,0,dp); 
    }
};