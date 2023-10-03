class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }

        int ans = 0;
        for(auto x: mp){
            if(x.second == 1) continue;
            else if(x.second == 2) ans++;
            else ans+=(x.second-1)*x.second/2;
        }

        return ans;
    }
};