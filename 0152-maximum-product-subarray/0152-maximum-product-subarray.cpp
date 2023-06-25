class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 1;
        int r= 1;
        int ans =INT_MIN;
        for(auto x: nums){
            l*=x;
            ans = max(ans, l);
            if(l == 0) l =1;
        }
        reverse(nums.begin(),nums.end());
        for(auto  x: nums){
            r*=x;
            ans = max(ans,r);
            if(r==0) r=1;
        }

        return ans;
    }
};