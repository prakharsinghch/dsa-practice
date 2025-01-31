class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(vector<vector<int>>& grid, int x, int y,int id){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid.size() || grid[x][y] != 1) return 0;

        grid[x][y] = id;
        int size = 1;
        for(auto d : dir){
            size += dfs(grid,x + d[0],y+d[1],id);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int id = 2;
        unordered_map<int,int> mp;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int size = dfs(grid,i,j,id);
                    mp[id] = size;
                    id++;
                }
            }
        }

        int ans = mp.empty() ? 0 : max_element(mp.begin(),mp.end(), [](const auto& a,const auto& b) {return a.second<b.second; })->second;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    unordered_set<int> connected;
                    int potential = 1;

                    for(const auto& d:dir){
                        int ni = i+ d[0];
                        int nj = j+d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            connected.insert(grid[ni][nj]);
                        }
                    }

                    for(const auto& id: connected){
                        potential+=mp[id];
                    }

                    ans = max(ans,potential);
                }
            }
        }

        return ans;

    }
};