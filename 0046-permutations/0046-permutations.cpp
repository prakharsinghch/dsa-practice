class Solution {
public:

    void recr(int i,vector<vector<int>>& ans,vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int ind = i;ind<nums.size();ind++){
            swap(nums[i],nums[ind]);
            recr(i+1,ans,nums);
            swap(nums[i],nums[ind]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  ans;
        recr(0,ans,nums);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};