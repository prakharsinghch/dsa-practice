class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> dif(nums.size()+1,0);
        for(const auto& q: queries){
            dif[q[0]]++;
            if(q[1]+1 < nums.size()) dif[q[1]+1]--;
        }
        int c = 0;
        for(int i=0;i<nums.size();i++){
            c+=dif[i];
            if(nums[i] > c) return false;
        }

        return true;
    }
};