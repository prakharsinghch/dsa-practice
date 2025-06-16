class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans= -1, mn = nums[0];
        for(int i=1;i<nums.size();i++){
            int dif = nums[i]-mn;
            if(mn > nums[i]) mn = nums[i];
            if(dif > ans) ans = dif;
        }

        return ans == 0 ? -1 : ans;
    }
};