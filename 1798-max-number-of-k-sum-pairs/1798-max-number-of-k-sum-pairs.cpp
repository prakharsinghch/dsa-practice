class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
    
        int ans = 0;
        sort(nums.begin(),nums.end());
        int i = 0, j = nums.size()-1;

        while(i<j){
            if(nums[i] + nums[j] < k) i++;
            if(nums[i] + nums[j] > k) j--;
            if(nums[i] + nums[j] == k && i!=j){
                ans++;
                i++;
                j--;
            }
        }

        return ans;

    }
};