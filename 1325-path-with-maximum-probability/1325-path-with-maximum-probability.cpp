class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back({edges[i][1], succProb[i]});
            v[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        double ans = 1.0;
        vector<double> dist(n,0.0);
        dist[start] = 1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            for(auto x: v[n]){
                int next_n = x.first;
                double pro = x.second;

                double new_pro = dist[n]*pro;

                if(new_pro > dist[next_n]){
                    dist[next_n] = new_pro;
                    q.push(next_n);
                } 
            }
        }
        return dist[end];
    }
};