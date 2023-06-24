class Solution {
public:

    int dp[1001][26][26] = {};

    int recr(vector<string>& words, int ind, char s, char e){
        if(ind >=  words.size()) return 0;
        if(dp[ind][s-'a'][e-'a'] != 0) return dp[ind][s-'a'][e-'a'];
        int n = words[ind].size();
        int res = INT_MAX;

        
        if(words[ind].back() == s) res = min(res, n-1 + recr(words,ind+1,words[ind][0] , e));
        else res = min(res, n+ recr(words,ind+1,words[ind][0], e) );

        if(words[ind][0] == e) res = min(res, n-1 + recr(words,ind+1,s,words[ind].back()));
        else res = min(res, n+recr(words,ind+1,s,words[ind].back()));

        return dp[ind][s-'a'][e-'a'] = res;

    }

    int minimizeConcatenatedLength(vector<string>& words) {
        return words[0].size() + recr(words,1,words[0][0],words[0].back());
         
    }
};