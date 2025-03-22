class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> x;
        int mx = INT_MIN;
        for(auto y: nums){
            if(y>=0) x.insert(y);
            mx = max(mx,y);
        }
        int ans=0;
        for(auto s: x) ans+=s;
        if(ans == 0) ans = mx;

        return ans;
    }
};