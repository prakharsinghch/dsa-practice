class Solution {
public:

    bool check(string& s, int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int recr(string& s, int i,int j,vector<int>& dp){
        if(i >= j || check(s,i,j)) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int k =i;k<j;k++){
            if(check(s,i,k)){
                int temp = recr(s,k+1,j,dp) +1;
                ans = min(ans,temp);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n= s.size();
        vector<int> dp(n+1,-1);
        return recr(s,0,n-1,dp);
    }
};