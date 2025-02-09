class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long x = 0;
        long long n = nums.size();
        for(int i=0;i<n;i++){
            x+=mp[nums[i]-i];
            mp[nums[i] - i]++;
        }

        return (n*(n-1)/2) - x;

    }
};