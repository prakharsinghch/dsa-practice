class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n,0);
        unordered_map<int,vector<int>> mp;
        for(auto x: pre){
            mp[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) q.push(i);
        }

        if(q.size() == 0) return false;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto y : mp[x]){
                indeg[y]--;
                if(indeg[y]== 0) q.push(y); 
            }
        }
        for(auto x: indeg){
            if(x != 0) return false;
        }
        return true;

    }
};