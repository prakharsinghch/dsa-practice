class Solution {
public:

    int recr(int i){
        if( i <= 1) return 1;
        return i*recr(i-1);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        int i = recr(n);
        vector<vector<int>> ans;

        for(int j=0;j<i;j++){
            ans.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }

        return ans;
    }
};