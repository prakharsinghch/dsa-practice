class Solution {
public:

    int recr(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j < 0|| j>=grid[0].size() || grid[i][j] == 0) return 0;

        int val = grid[i][j];
        grid[i][j] = 0;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(auto d : dir){
            val+=recr(i+d[0], j+d[1], grid);
        }

        return val;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n= grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] > 0) {
                    ans = max(ans,recr(i,j,grid));
                }
            }
        }

        return ans;
    }
};