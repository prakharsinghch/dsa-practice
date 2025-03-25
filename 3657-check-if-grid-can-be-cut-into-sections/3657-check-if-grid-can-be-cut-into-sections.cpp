class Solution {
public:

    bool check(vector<vector<int>>& v){
        sort(v.begin(),v.end());
        int mx = v[0][1];
        int sec = 0;
        for(auto x: v ){
            if(x[0] >= mx){
                sec++;
            }
            mx = max(mx,x[1]);
        }

        return sec >= 2;

    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;

        for(auto z: rectangles){
            x.push_back({z[0],z[2]});
            y.push_back({z[1],z[3]});
        }

        return check(x) || check(y);

    }
};