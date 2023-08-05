class Solution {
public:

    static bool comp(vector<int> a, vector<int> b){
        double x = sqrt(a[0]*a[0] + a[1]*a[1]);
        double y = sqrt(b[0]*b[0] + b[1]*b[1]);

        return x<y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(),comp);
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[i]);
        }

        return ans;
    }
};