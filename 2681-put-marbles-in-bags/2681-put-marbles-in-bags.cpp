class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> v;
        for(int i=1;i<weights.size();i++){
            int sum = 0;
            sum = weights[i-1]+weights[i];
            v.push_back(sum);
        }

        sort(v.begin(),v.end());
        int n=v.size();
        long long ml = 0 ,mx = 0;
        for(int i=0;i<k-1;i++){
            ml += v[i];
            mx += v[n-i-1];
        }

        return mx-ml;
    }
};