class Solution {
public:

    int val = 0;
    void solve(vector<vector<int>>& grid, int rS, int rE, int cS, int cE){
        int size = rE-rS;
        if(size ==1){
            grid[rS][cS] = val++;
            return;
        }
        int midR = rS+size/2;
        int midC = cS+size/2;

        solve(grid, rS, midR, midC, cE);
        solve(grid,midR,rE, midC,cE);
        solve(grid,midR,rE,cS,midC);
        solve(grid,rS,midR,cS,midC);
    }

    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        vector<vector<int>> grid(size,vector<int>(size));
        solve(grid,0,size,0,size);
        return grid;
    }

};