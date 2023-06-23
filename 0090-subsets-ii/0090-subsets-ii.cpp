class Solution {
public:

    void recr(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int ind)
    {
      
        ans.push_back(temp);
            

        for(int i=ind; i<nums.size();i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            recr(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        recr(nums,temp,ans, 0);
        return ans;
    }
};