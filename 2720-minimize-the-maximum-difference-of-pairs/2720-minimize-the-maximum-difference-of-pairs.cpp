class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int lo= -1, hi = 1e9+7;

        while(lo< hi-1){
            int mid = lo + (hi-lo)/2;
            int a = 0;
            for(int i=1;i<n;i++){
                if(nums[i] - nums[i-1] <= mid){
                    a++;
                    i++;
                }
            }
            if(a>=p) hi=mid;
            else lo = mid;
        }

        return hi;
    }
};