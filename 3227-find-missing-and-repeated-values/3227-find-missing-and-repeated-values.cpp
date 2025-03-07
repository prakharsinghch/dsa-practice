class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int  n = grid.size();
        unordered_map<int,int> mp;
        for(auto x: grid){
            for(auto y : x){
                mp[y]++;
            }
        }

        vector<int> ans(2,0);
        for(int i=1;i<=n*n;i++){
            if(mp[i] == 2) ans[0] = i;
            if(mp[i] == 0) ans[1] = i;
        }

        return ans;
    }

};