class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        if(m == 0 || n == 0) return max(m,n);
        vector<vector<int>> arr(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) arr[i][0] = i;
        for(int j=0;j<=n;j++) arr[0][j] = j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]) arr[i][j] = arr[i-1][j-1];
                else{
                    int in = arr[i][j-1];
                    int del = arr[i-1][j];
                    int rep = arr[i-1][j-1];

                    arr[i][j] = 1+min({in,del,rep});
                }
            }
        }

        return arr[m][n];
    }
};