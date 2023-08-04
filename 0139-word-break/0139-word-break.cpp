class Solution {
public:

    bool recr(string s, unordered_set<string> t,int start,vector<int>& dp){
        if(start == s.length()) return true;

        if(dp[start] != -1) return dp[start];

        for(int i=start;i<s.length();i++){
            string s1 = s.substr(start,i+1-start);
            if(t.count(s1) && recr(s,t,i+1,dp) ){
                dp[start] = true;
                return true;
            }
        }
        
        return dp[start]=false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> t(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return recr(s,t,0,dp);
    }

};