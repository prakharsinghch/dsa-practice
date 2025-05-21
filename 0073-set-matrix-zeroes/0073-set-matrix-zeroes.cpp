class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size() , n=matrix[0].size();
        set<int> row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto x: row){
            for(int i=0;i<n;i++) matrix[x][i] = 0;
        }

        for(auto x: col){
            for(int i=0;i<m;i++) matrix[i][x] = 0;
        }


    }
};