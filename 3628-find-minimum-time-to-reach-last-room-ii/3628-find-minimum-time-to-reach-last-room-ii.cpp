class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size() , m = moveTime[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({0,0,0});
        moveTime[0][0] = 0 ;

        vector<vector<int>> dir = {{1,0} , {0,1} , {-1,0}, {0,-1}};
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int t = x[0];
            int r = x[1];
            int c = x[2];
            if(t >= dp[r][c]) continue;
            if(r == n-1 && c == m-1) return t;
            dp[r][c] = t;
            
            for(auto& d : dir){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && dp[nr][nc] == INT_MAX){
                    int cost = (r+c)%2+1;
                    int start = max(moveTime[nr][nc], t);
                    int nxt = start+cost;
                    pq.push({nxt,nr,nc});
                }
            }
        }

        return -1;
    }
};