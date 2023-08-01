class Solution {
public:

    void recr(int ind, int i, int n, int k, vector<int> v, vector<vector<int>>& ans ){
        if(ind == k){
            ans.push_back(v);
            return;
        }

        for(int j=i;j<=n;j++){
            v.push_back(j);
            recr(ind+1,j+1,n,k,v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        recr(0,1,n,k,v,ans);
        return ans;
    }
};