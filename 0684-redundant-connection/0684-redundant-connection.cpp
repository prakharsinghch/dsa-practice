class Solution {
public:

    bool check(unordered_map<int,vector<int>>& mp, int u, int v){
        set<int> vis;
        stack<int> s;
        s.push(u);
        while(!s.empty()){
            int x = s.top();
            s.pop();
            if(vis.count(x)) continue;
            vis.insert(x);
            if(x == v) return true;
            for(auto y:mp[x]) s.push(y);
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto x : edges){
            int u = x[0], v =x[1];
            if(mp.count(u) && mp.count(v) && check(mp,u,v)) return x; 

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        return {};
    }
};