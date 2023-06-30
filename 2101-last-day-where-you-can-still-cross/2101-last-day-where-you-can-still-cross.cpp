class Solution {
public:



    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(i == grid.size()-1) return true;

        int x[4] = {0,1,-1,0};
        int y[4] = {1,0,0,-1};
        
        grid[i][j] = 1;

        for(int m = 0;m<4;m++){
            int k = i+x[m];
            int l = j+y[m];

            if(k >=0 && l >=0  && k<grid.size() && l<grid[0].size() && grid[k][l] == 0){
                if(dfs(grid,k,l)) return true;
            }
        }

        return false;

    }

    bool check(vector<vector<int>>& grid, int mid){
       if(mid < grid[0].size()) return true;


       for(int i =0;i<grid[0].size();i++){
           if(grid[0][i] == 0) {
               if(dfs(grid,0,i)) return true;
           }
       }

       return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans = 0;
        int l = 0, h=cells.size()-1;

        while(l<=h){
            int mid  = l + (h-l)/2;
            vector<vector<int>> grid(row,vector<int>(col,0));

            for(int i=0;i<mid;i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            if(!check(grid,mid)) h= mid-1;
            else l = mid+1;
        }
        return h;
    }
};