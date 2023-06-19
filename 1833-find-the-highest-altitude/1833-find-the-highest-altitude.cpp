class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(gain[0]);
        int res =  max(ans[0],ans[1]);
        for(int i=1;i<gain.size();i++)
        {
            res = max(res,ans[i]+gain[i]);
            ans.push_back(ans[i]+gain[i]); 
        }
        return res;
    }
};