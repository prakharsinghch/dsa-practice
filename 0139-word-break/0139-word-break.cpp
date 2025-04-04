class Solution {
public:

    bool recr(string s,set<string>& st,int start,vector<int>& dp){
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];
        for(int i=start;i<s.size();i++){
            string s1 = s.substr(start,i+1-start);
            if(st.count(s1) && recr(s,st,i+1,dp)) return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.size()+1,-1);
        for(auto x: wordDict) st.insert(x);

        return recr(s,st,0,dp);

    }
};