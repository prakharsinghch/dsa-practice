class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0;
        for(int i= 0;i<=nums.size()-3;i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 1 ? 0: 1;
                nums[i+2] = nums[i+2] == 1 ? 0: 1;
                c++;
            }
        }
        int x = 0 ;
        for(auto y: nums) x+=y;
        return x == nums.size() ? c : -1;
    }
};