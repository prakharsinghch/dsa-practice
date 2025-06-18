class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i <= nums.size()-3;i+=3){
            vector<int>res;
            for(int j=0;j<3;j++){
                if(res.size() == 0) res.push_back(nums[i+j]);
                else if(abs(nums[i+j]-res[0]) <= k) res.push_back(nums[i+j]);
                else return {};
            }

            ans.push_back(res);
        }

        return ans;
    }
};