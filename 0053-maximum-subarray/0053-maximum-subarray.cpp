class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=0;
        int ans=INT_MIN;
        for(auto x: nums){
            mx+=x;
            ans = max(mx,ans);
            if(mx<0) mx = 0;
        }
        return ans;
    }
};