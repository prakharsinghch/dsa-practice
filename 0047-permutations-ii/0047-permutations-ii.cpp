class Solution {
public:

    void recr(vector<int>& nums,vector<int>temp, set<vector<int>>& s, int ind){
        if(ind == nums.size()){
            s.insert(temp);
            return;
        }
        for(int i =ind;i<temp.size();i++){
            swap(temp[i], temp[ind]);
            recr(nums,temp,s,ind+1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp = nums;
        recr(nums,temp,s,0);
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;

    }
};