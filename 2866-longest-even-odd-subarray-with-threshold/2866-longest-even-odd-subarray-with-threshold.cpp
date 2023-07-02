class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        int x = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0 && ans == 0 && nums[i] <= threshold) ans = 1;
            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[i] % 2 == 0 && nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold && nums[i] <= threshold )  {
                    x++;
                    ans = max(ans, x);
                } else 
                    break;
            }
            x= 1;
        }
        return ans;
    }
};