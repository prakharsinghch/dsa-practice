class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            long long x = nums[i];
            for(int j=i+1;j<nums.size();j++){
                long long z = x-nums[j];
                for(int k=j+1;k<nums.size();k++){
                    long long y = z*nums[k];
                    ans = max(ans,y);
                }
            }
        }

        return ans;
    }
};