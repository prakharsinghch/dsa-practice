class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int i=0;
        // for(i=0;i<matrix.size();i++)
        // {
        //     if(matrix[i][0] > target) 
        //     {
        //         break;
        //     }
        // }

        // if(i==0) return false;

        // if(binary_search(matrix[i-1].begin(), matrix[i-1].end(),target)) return true;

        // return false;
        int n=matrix[0].size();
        int m=matrix.size();

        int i=0,j=n-1;

        while(i<m && j>-1)
        {
            int ans=matrix[i][j];
            if(ans == target) return true;
            if(ans > target) j--;
            else i++;
        }

        return false;
        

    }
};