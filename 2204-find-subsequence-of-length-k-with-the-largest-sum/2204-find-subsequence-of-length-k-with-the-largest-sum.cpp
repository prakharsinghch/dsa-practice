class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i =0 ;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};