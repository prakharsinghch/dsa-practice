class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<long long> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i] += 1L*i*x;
            int cur = nums[i];
            for(int j=0;j<nums.size();j++){
                cur = min(cur,nums[(i-j+nums.size())%nums.size()]);
                ans[j]+=cur;
            }
        }

        sort(ans.begin(),ans.end());
        return ans[0];
    }
};