const int mod = 1e9+7, maxi = 1e4+10, maxp = 15;
int dp[maxi + maxp][maxp+1];
vector<int> pcnt[maxi];
int sieve[maxi];

class Solution {
public:
    void solve(){
        if(dp[0][0]) return;
        for(int i=2; i<maxi; i++){   //Mark the primes
            if(sieve[i]==0){
                for(int j=i; j<maxi; j+=i) sieve[j] = i;
            }
        }

        for(int i=2; i<maxi; i++){   //Count the factors for each i
            int curr = i;
            while(curr > 1){
                int p = sieve[curr];
                int cnt = 0;
                while(curr%p == 0){
                    curr/=p;
                    cnt++;
                }
                pcnt[i].push_back(cnt);
            }
        }

        dp[0][0] = 1;
        for(int i=1; i<maxi+maxp; i++){    //fill the dp table
            dp[i][0] = 1;
            for(int j=1; j<=min(i, maxp); j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        solve();
        for(int i=1; i<=maxValue; i++){
            long long mul = 1;
            for(int j: pcnt[i]){
                mul = mul*dp[n+j-1][j]%mod;
            }
            ans = (ans+mul)%mod;
        }
        return ans;
    }
};