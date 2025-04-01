class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1;
        int ans = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            pro*=nums[i];
            ans = max(ans,pro);
            if(pro==0) pro = 1;
        }
        int ans1 = INT_MIN;
        pro = 1;
        for(int i = nums.size()-1;i>0;i--){
            pro*=nums[i];
            ans1= max(ans1,pro);
            if(pro==0) pro = 1;
        }
        return max(ans,ans1);
    }
};