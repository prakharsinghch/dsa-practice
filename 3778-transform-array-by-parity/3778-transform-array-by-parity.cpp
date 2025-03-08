class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) nums[i]=1;
            else nums[i] = 0;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};