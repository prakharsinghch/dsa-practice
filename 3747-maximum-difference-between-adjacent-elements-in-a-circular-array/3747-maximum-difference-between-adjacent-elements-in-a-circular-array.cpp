class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            mx = max(mx, abs(nums[i]-nums[i+1]));
        }
        mx = max(mx, abs(nums[0]-nums[nums.size()-1]));
        return mx;
    }
};