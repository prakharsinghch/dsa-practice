class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int> a,b;
        for(auto x: nums) a[x]++;
        int i=0,j=0,ans=0;
        while(i<nums.size()){
            b[nums[i]]++;
            while(j<=i && b.size() == a.size()){
                if(--b[nums[j]] == 0) b.erase(nums[j]);
                j++;
                ans+=(nums.size()-i);
            }
            i++;
        }

        return ans;
    }
};