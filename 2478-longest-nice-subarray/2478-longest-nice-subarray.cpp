class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1, l  = 0 , used = 0;
        for(int i = 0;i < nums.size();i++){
            while( (used & nums[i]) != 0){
                used ^= nums[l];
                l++;
            }
            used |= nums[i];
            ans = max(ans,i-l+1);
        }

        return ans;
    }
};