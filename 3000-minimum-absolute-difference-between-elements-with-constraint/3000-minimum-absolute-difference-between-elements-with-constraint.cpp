class Solution {
public:
    
   
    
    int minAbsoluteDifference(vector<int>& nums, int x) {

        multiset<int> m;
        int ans = INT_MAX;
        for(int i  = 0;i<nums.size();i++){
            if(i-x >= 0) m.insert(nums[i-x]);
            auto c = m.upper_bound(nums[i]);

            if(c != m.end()) ans = min(ans, abs(nums[i] - *c));
            if (c!= m.begin())ans = min(ans, abs(nums[i] - *prev(c)));
        }

        return ans;    

        
        
    }
};