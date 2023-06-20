class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<long long> pre(nums.size());
        pre[0] = nums[0];

        for(int i=1;i<nums.size();i++) pre[i] = pre[i-1]+nums[i];

        vector<int> ans(nums.size(),-1);

        int c = 2*k;
        int m = c+1;
        for(int i=0;i<n-2*k;i++){
            long long x = pre[c+i];
            if(i >0)  x-=pre[i-1];
            ans[k+i] = int(x/m);
            // cout<<pre[c+i]<<" "<<c+i<<endl;
        }

       
        
        return ans;
    }
};