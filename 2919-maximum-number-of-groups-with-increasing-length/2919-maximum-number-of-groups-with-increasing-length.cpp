class Solution {
public:
    int maxIncreasingGroups(vector<int>& u) {
        sort(u.begin(),u.end());
        long long sum = 0, ans = 0;
        for(auto x: u){
            sum+=x;
            if(sum>=(ans+2)*(ans+1)/2) ans++;
            
        }
        return ans;
    }
};