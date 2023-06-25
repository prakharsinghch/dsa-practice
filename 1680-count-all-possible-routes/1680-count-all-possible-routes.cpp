class Solution {
public:
    int mod=1e9+7;
    int solve(vector<vector<int>>&dp,vector<int>&l,int current,int &finish,int fuel){
        int n=l.size();
        if(fuel<0)return 0;
        if(dp[current][fuel]!=-1)return dp[current][fuel];
        int ans=0;
        if(current==finish)ans++;
        for(int next=0;next<n;next++){
            if(next!=current){
                ans=(ans%mod+solve(dp,l,next,finish,fuel-abs(l[current]-l[next]))%mod)%mod;
            }
        }
        return dp[current][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        int n=l.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return solve(dp,l,start,finish,fuel);
    }
};