class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        map<pair<int,int>,int>  mp;

        long long ans = 0;
        
        for(int i = 0;i<c.size();i++){
            for(int j= 0;j<=k;j++){
                int x = j^c[i][0];
                int y = (k-j)^c[i][1];
                if(mp.find({x,y}) != mp.end()){
                    ans+=mp[{x,y}];
                }
            }

            mp[{c[i][0] , c[i][1]}]++;
        }
        
        
        return ans;
    }
};