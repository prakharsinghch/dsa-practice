class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,p=1,c=0;
        int n = nums.size();
        if(k<=1) return 0;
        while(r<n){
            p*=nums[r];
            while(p>=k) p/=nums[l++];
            c+=1 +(r-l);
            r++;
        }

        return c;
    }
};