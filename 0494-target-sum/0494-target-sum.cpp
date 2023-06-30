class Solution {
public:

    int recr(vector<int>& nums, int target, int i){
        if(i == nums.size() ) {
            if(target == 0) return 1;
            return 0;
        }

        int add = recr(nums, target+nums[i], i+1);
        int sub = recr(nums,target-nums[i],i+1);

        return add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return recr(nums,target,0);
    }
};