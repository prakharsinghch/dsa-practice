class Solution {
public:

    int solve(int i,int j, int m,int n,vector<vector<int>>& v){
        if(v[i][j] != -1) return v[i][j];
        if(i == m-1 || j == n-1) return 1;

        v[i][j] = solve(i+1,j,m,n,v) + solve(i,j+1,m,n,v);
        return v[i][j];
    }

    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> v(m,vector<int>(n,-1));
        ans = solve(0,0,m,n,v);
        return ans;
    }
};