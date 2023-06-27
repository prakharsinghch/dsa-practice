class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;       
        for(auto x: nums1)
        {
            for(auto y: nums2){
                int s = x+y;
                if(pq.size() < k) pq.push({s,{x,y}});
                else if(s<pq.top().first){
                    pq.pop();
                    pq.push({s,{x,y}});
                }
                else if(s>pq.top().first) break;
            }
        }

        vector<vector<int>> ans;
        int j= pq.size();
        k = min(k,j);

        for(int i = 0;i<k;i++) 
        {
            auto x = pq.top();
            ans.push_back({x.second.first, x.second.second});
            pq.pop();
        }

        return ans;
        
    }
};