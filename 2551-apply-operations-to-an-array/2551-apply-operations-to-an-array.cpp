class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]){
                nums[i-1] = nums[i]*2;
                nums[i] = 0;
            }
        }
        for(auto x: nums){
            if(x!=0) ans.push_back(x);
        }
        while(ans.size() < nums.size()) ans.push_back(0);

        return ans;
    }
};