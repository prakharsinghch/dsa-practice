class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        for(int i= 0 ; i <nums.size();i++)
        {
            for(int j= 0;j<nums.size() ;j++){
                if(abs(i-j) <= k && nums[j] == key) ans.insert(i);
            }
        }

        vector<int> res;
        for(auto x: ans){
            res.push_back(x);
        }

        return res;
    }
};