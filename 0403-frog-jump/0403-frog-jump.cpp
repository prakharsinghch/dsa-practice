class Solution {
public:

    bool recr(vector<int>& stones, int i, int k,vector<vector<int>>& dp){
        if(i == stones.size()-1) return true;

        bool ans = false;
        if(dp[i][k] != -1) return dp[i][k];


        for(int j = i+1;j<stones.size();j++){
            if(stones[j] > (stones[i] + k+1) ) break;
            else if(stones[j] == (stones[i] + k-1)){
                ans |= recr(stones,j,k-1,dp);
            }
            else if(stones[j] == (stones[i] + k)){
                ans |= recr(stones,j,k,dp);
            }
            else if(stones[j] == (stones[i] + k+1)){
                ans |=  recr(stones,j,k+1,dp);
            }
        }
        

        return dp[i][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(2000,-1));
        return recr(stones, 0,0,dp);   
    }
};