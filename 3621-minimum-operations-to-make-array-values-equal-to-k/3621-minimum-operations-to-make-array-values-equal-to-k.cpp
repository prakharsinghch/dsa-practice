class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        if(mini < k) return -1;

        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > k){
                c++;
                while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
            }
        }

        return c;
    }
};