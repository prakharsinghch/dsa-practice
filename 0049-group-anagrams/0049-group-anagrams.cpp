class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            mp[x].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto x: mp){
            vector<string> y;
            for(auto i: x.second){
                y.push_back(strs[i]);
            }
            ans.push_back(y);
        }

        return ans;
    }
};