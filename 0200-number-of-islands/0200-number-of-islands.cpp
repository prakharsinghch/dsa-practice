class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dir = {0,-1,0,1,0};

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        if(x < 0 || y <0 || x >=m || y >= n || grid[x][y] != '1') continue;

                        grid[x][y] = 0;
                        for(int i=1;i<dir.size();i++){
                            int rx = x + dir[i-1], ry = y + dir[i];
                            if(rx < 0 || ry <0 || rx >=m || ry >= n || grid[rx][ry] != '1') continue;
                            else{
                                q.push({rx,ry});
                            }
                        }
                    }
                }
            }

        }
         return ans;
    }
};