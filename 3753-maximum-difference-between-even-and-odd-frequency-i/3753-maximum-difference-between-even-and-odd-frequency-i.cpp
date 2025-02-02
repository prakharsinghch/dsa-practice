class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }

        int mx=INT_MIN,mn=INT_MAX;
        for(auto x: mp){
            if(x.second%2){
                mx = max(mx,x.second);
            }
            if(x.second%2 == 0) mn = min(mn,x.second);
        }

        return mx-mn;
    }
};