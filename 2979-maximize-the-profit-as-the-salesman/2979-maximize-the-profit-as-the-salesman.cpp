class Solution {
public:

    bool static comp(const vector<int>& a, const vector<int>& b){
        if(a[1] < b[1]) return true;
        if(a[1] == b[1]){
            if(a[0] < b[0]) return true;
            else if(a[0] == b[0]){
                if(a[2] > b[2]) return true;
                return false;
            }
        }

        return false;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(), comp);

        int x = offers.size();

        vector<int> dp(n+1,0);

        int ans =0;

        int j = 0;
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i];

            while(j < x && offers[j][1] == i){
                dp[i+1] = max(dp[i+1] , offers[j][2] + dp[offers[j][0]]);
                ans = max(dp[i+1], ans);
                j++;
            }
        }



        return ans;

    }
};