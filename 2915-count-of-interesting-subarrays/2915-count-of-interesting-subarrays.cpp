class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0, eq = 0;
        unordered_map<int,long long> mp;
        mp[0] = 1;
        for(int i:nums){
            if(i%modulo == k) eq++;
            int rem = eq%modulo;
            int need  = (rem-k+modulo)%modulo;
            ans+=mp[need];
            mp[rem]++;
        }

        return ans;
    }
};