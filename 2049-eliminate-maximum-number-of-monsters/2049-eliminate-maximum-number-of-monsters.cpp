class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> v;
        for(int i= 0;i<n;i++){
            double t = (double)dist[i]/ (double)speed[i];
            
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        int c = 0,ans = 0;
        for(auto x: v){
            cout<<x<<" "<<ans;
            if(x <= ans) return ans;
            ans++;
        }

        return n;

    }
};