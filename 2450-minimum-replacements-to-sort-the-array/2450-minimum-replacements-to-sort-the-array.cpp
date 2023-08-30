class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0, mx = nums[nums.size()-1];

        for(int i=nums.size()-2;i >= 0;i--){
            if(nums[i] > mx){
                int z = ceil(nums[i] /double( mx));
                ans+=z-1;
                mx = nums[i] / z;
            }
            else mx = nums[i];
        }

        return ans;

    }
};