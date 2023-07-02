class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n+1,true);
        prime[0] = false;
        prime[1] = false;

        for(int i=2;i*i <= n;i++){
            if(prime[i] == true){
                for(int j=i*i;j<=n; j += i){
                    prime[j] = false;
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=2;i<=(n-1);i++){
            int j = n-i;
            if(prime[i] && prime[j] && i<=j){
                ans.push_back({i,j});
            }
        }

        return ans;
    }
};