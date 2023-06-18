class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> pre(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++){
            pre[i] = abs(nums[i] - nums[i+1]);
        }
        sort(pre.begin(),pre.end());
        return pre[0];
    }
};