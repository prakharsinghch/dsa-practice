class Solution {
public:

    int m = 1e9+7;

    // int check(int i,int n,vector<vector<int>>& v){

    //     if(n == 0) return 0;
    //     if(n == 1) return 1;

    //     int ans = 0;
    //     for(int j=0;j<v[i].size();j++){
    //         ans += check(v[i][j],n-1,v);
    //     }

    //     return ans; 
    // }

    int knightDialer(int n) {
        vector<vector<int>> v(10);
        v[0] = {4,6};
        v[1] = {6,8};
        v[2] = {7,9};
        v[3] = {4,8};
        v[4] = {0,3,9};
        v[5] = {};
        v[6] = {0,1,7};
        v[7] = {2,6};
        v[8] = {1,3};
        v[9] = {2,4};

        long long int ans = 0;

        vector<vector<long long int>> dp(n+1,vector<long long int>(10,0));

        for(int i=0;i<10;i++) dp[1][i] = 1;

        for(int i=2;i<n+1;i++){
            for(int j=0;j<10;j++){
                for(int k = 0 ; k<v[j].size();k++){
                    dp[i][j] += dp[i-1][v[j][k]];
                }
                dp[i][j]%=m;
            }
        }

        for(auto x: dp[n]) ans+=x;

        return ans%m;

    }
};