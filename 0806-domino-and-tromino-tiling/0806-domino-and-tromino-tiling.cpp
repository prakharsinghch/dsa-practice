class Solution {
public:
    int m = 1e9+7;
    int numTilings(int n) {
        vector<int> v(n+1);
        if(n<=2) return n;
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for(int i = 3;i<=n;i++){
            v[i] = ((2*v[i-1])%m + v[i-3])%m;
        }

        return v[n];
    }
};