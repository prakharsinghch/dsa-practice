class Solution {
public:
    int mod=1e9+7;
    int possibleStringCount(string word, int k) {
        int n=word.size();
        if(n<k) return 0;
        if(n==k) return 1;

        vector<int> seq = {1};
        for(int i=1;i<n;i++){
            if(word[i] == word[i-1]) seq.back()++;
            else seq.push_back(1);
        }
        int  m = seq.size();

        long long total =1;
        bool takeMod = 0;
        for(int x : seq){
            total*=x;
            if(total >= mod){
                total%=mod;
                takeMod = 1;
            }
        }

        if(total ==1 && !takeMod) return 1;

        if(k <= m) return total;

        int maxT = k-m-1;
        long long dp[2][2000] = {0}, prefix[2001]={0};
        dp[0][0]=1;

        for(int j=0;j<m;j++){
            int s = seq[j];
            for(int i=0;i<=maxT;i++){
                prefix[i+1] = (prefix[i] + dp[j&1][i])%mod;
                int L = max(0,i-(s-1)), R = i;
                dp[(j+1)&1][i] = (prefix[R+1]-prefix[L] + mod)%mod;
            }
        }

        long long lessK = 0;
        for(long long x : dp[m&1]) lessK = (lessK+x)%mod;

        return (total-lessK+mod)%mod;
    }
};