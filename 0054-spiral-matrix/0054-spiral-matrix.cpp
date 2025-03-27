class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int a = 0,b=0,c=m-1,d=n-1;

        while(ans.size()<m*n){
            for(int i=b;ans.size()<m*n && i<=d;i++){
                ans.push_back(matrix[a][i]);
            }
            a++;
            for(int i=a;ans.size()<m*n && i<=c;i++){
                ans.push_back(matrix[i][d]);
            }
            d--;
            for(int i=d;ans.size()<m*n && i>=b;i--){
                ans.push_back(matrix[c][i]);
            }
            c--;
            for(int i=c;ans.size()<m*n && i>=a;i--){
                ans.push_back(matrix[i][b]);
            }
            b++;
        }

        return ans;
    }
};