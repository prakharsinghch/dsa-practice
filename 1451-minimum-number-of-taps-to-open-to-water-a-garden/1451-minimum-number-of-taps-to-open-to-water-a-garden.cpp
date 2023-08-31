class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        for(int i=0;i<ranges.size();i++){
            v.push_back({i-ranges[i], i+ ranges[i]});
        }

        sort(v.begin(),v.end());

        int ans =1;
        int b = INT_MIN,a = 0;
        int i;

        for(i=0;i<n;i++){
            if(v[i].first > 0) break;
            b = max(b, v[i].second);
        }

        if(b >= n) return ans;


        for(int j=i;b<n;){
            int x = b;
            while(j<=n && v[j].first <= b){
                x = max(x,v[j].second);
                j++;
            }

            if(x == b) return -1;

            b = x;
            ans++;
        }

        return ans;


    }
};