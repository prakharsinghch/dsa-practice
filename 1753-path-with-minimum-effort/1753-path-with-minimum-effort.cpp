class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));

        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>> , greater<>> pq;

        pq.push({0,0,0});

        dis[0][0] = 0;

        int dirc[4][2] = { {0,1}, {-1,0},{1,0},{0,-1} };

        while(!pq.empty()){
            auto[effort, x,y] = pq.top();
            pq.pop();

            if(effort > dis[x][y]) continue;

            if(x == n-1 && y == m-1) return effort;

            for(auto dir: dirc){
                int nx = x + dir[0], ny = y + dir[1];

                if(nx>= 0 && nx < n && ny>=0 && ny < m){
                    int new1 = max(effort,abs(h[x][y] - h[nx][ny]));
                    if(new1 < dis[nx][ny]){
                        dis[nx][ny] = new1;
                        pq.push({new1, nx,ny});
                    }
                }
            }
        }

        return -1;
    }
};