class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int m = points.size();
        int ans = 0;
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(points.begin(),points.end(),comp);
        for(int i=0;i<m;i++){
            for(int j = i+1;j<m;j++){             
                if(points[j][1]<=points[i][1]){
                    bool check = true;  
                    for(int k=i+1;k<j;k++){
                       // if(k == i || k == j) continue;
                        // if(points[i][0] <= points[k][0] && points[k][0] <= points[j][0]){
                        //     check=false;
                        // }
                        if(points[i][1] >= points[k][1] && points[k][1] >= points[j][1]){
                            check=false;
                        }
                    }   
                    if(check) ans++;   
                }
            }
        }   

        return ans;
    }
};