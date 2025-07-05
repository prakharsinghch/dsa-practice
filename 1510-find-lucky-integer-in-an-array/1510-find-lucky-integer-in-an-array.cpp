class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x: arr) mp[x]++;

        int ans = -1;
        for(auto x : mp){
            if(x.second == x.first) ans = max(ans,x.second);
        }

        return ans;
    }
};