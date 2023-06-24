class Solution {
public:

    void recr(vector<int>& x, int sum, int ind, vector<int> v,vector<vector<int>>& ans){
        if(sum == 0) ans.push_back(v);

        for(int i=ind;i<x.size();i++){
            if(i!= ind && x[i] == x[i-1]) continue;
            if(sum<0) break;
            v.push_back(x[i]);
            recr(x,sum-x[i],i+1,v,ans);
            v.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        recr(candidates, target, 0, v, ans);
        return ans;
    }
};