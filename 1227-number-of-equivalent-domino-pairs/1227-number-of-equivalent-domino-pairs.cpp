class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mp;
        int ans = 0;
        for(auto x: dominoes){
            if(x[0] > x[1]) swap(x[0],x[1]);
            ans+= mp[{x[0],x[1]}]++;
        } 

        return ans;
    }
};