class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> row = {1,1};
        for(int i=1;i<rowIndex;i++){
            vector<int> newRow;
            newRow.push_back(1);
            for(int j =1 ;j<row.size();j++){
                newRow.push_back(row[j-1] + row[j]);
            }
            newRow.push_back(1);
            row = newRow;
        }

        return row;
    }
};