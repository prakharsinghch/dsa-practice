class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> suf;
        suf.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>=0;i--){
            suf.push_back(suf.back()+nums[i]);
        }
        reverse(suf.begin(),suf.end());
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            pre.push_back(pre.back()+nums[i]);
        }
        int ans = 0;
        for(int i=1;i<suf.size();i++){
            // cout<<pre[i-1]<<" "<<suf[i]<<endl;
            if((pre[i-1]-suf[i])%2 == 0) ans++; 
        }
        return ans;

    }
};