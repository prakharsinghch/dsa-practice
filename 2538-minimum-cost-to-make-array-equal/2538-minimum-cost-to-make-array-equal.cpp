class Solution {
public:

    long long ct(vector<int>& nums, vector<int>& cost, int val){
        long long ans =0LL;
        for(int i =0;i<nums.size();i++){
            ans+=1LL*abs(val-nums[i])*cost[i];
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        int n = nums.size();
        int low=nums[0], high = nums[0];
        for(auto x: nums){
            low = min(low,x);
            high = max(high,x);
        }
        long long c1=0, c2=0;
        long long ans=0;
        while(low<high){
            int mid = (high+low)/2;
            c1 = ct(nums,cost,mid);
            c2 = ct(nums,cost,mid+1);
            if(c1>c2){
                ans = c2;
                low = mid+1;
            }
            else{
                ans = c1;
                high = mid;
            }
        }
        return ans;
    }
};