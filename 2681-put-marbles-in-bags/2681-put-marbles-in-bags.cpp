class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<int> v;
        for(int i = 1;i<w.size();i++){
            int sum = 0;
            sum = w[i-1]+w[i];
            v.push_back(sum);
        }

        sort(v.begin(),v.end());    
        long long mi=0, mx=0;
        int n = v.size();
        for(int i = 0 ;i<k-1;i++){
            mi += v[i];
            mx += v[n-i-1];
        }

        return mx-mi;
    }
};