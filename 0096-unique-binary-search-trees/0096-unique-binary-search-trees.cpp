class Solution {
public:
    int numTrees(int n) {
        vector<int> u(n+1,1);
        for(int nodes = 2;nodes<=n;nodes++){
            int x = 0;
            for(int r = 1;r<=nodes;r++){
                x+=u[r-1]*u[nodes-r];
            }
            u[nodes] =x;
        }
        return u[n];
    }
};