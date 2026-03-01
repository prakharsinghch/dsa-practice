class Solution {
public:
    int minPartitions(string n) {
        int ans = INT_MIN;
        for(auto x : n){
            ans = max(ans,x-'0');
        }

        return ans;
    }
};