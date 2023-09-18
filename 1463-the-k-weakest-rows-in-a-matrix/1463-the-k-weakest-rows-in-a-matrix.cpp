class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> mp;
        int m = 0;
        for(auto x: mat){
            int ans = 0;
            for(auto j : x){
                if(j == 1) ans++;
            }

            mp[ans].push_back(m);
            m++;
        }

        vector<int> ans;

        for(auto x: mp){
            sort(x.second.begin(), x.second.end());
            for(int i = 0;i<x.second.size() && k>0;i++ , k--){
                    ans.push_back(x.second[i]);
                }
            
        }


        return ans;

        
    }
};