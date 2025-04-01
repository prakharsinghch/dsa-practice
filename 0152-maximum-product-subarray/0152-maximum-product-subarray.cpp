class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            pro*=nums[i];
            ans = max(ans,pro);
            if(pro<0) pro = 1;
        }
        return ans;
    }
};