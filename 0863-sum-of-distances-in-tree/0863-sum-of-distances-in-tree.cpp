class Solution {
public:
    void dfs(int i, int p, vector<int>& ans, vector<int>& join, vector<int>adj[]){
        for(auto it: adj[i]){
            if(p!=it){
                dfs(it, i, ans, join, adj);
                join[i]+=join[it];
                ans[i]+=ans[it]+join[it];
            }
        }
    }
    void dfss(int i, int p, vector<int>& ans, vector<int>& join, vector<int>adj[]){
        for(auto it: adj[i]){
            if(p!=it){
                ans[it]+=ans[i]+join[0]-join[it]-ans[it]-join[it];
                dfss(it, i, ans, join, adj);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans(n, 0), join(n, 1);
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, -1, ans, join, adj);
        //for(int i=0; i<n; i++){cout<<ans[i]<<" ";}cout<<endl;
        //for(int i=0; i<n; i++){cout<<join[i]<<" ";}cout<<endl;
        dfss(0, -1, ans, join, adj);
        //for(int i=0; i<n; i++){cout<<ans[i]<<" ";}cout<<endl;
        return ans;
    }
};