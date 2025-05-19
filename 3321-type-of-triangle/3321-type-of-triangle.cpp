class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums[0] == nums.back()) return "equilateral";
        if(nums[0] + nums[1] > nums[2] ) {
            if(nums[0] == nums[1] || nums[1] == nums[2]) return "isosceles";
            return "scalene";
        }  

        return "none";
    }
};