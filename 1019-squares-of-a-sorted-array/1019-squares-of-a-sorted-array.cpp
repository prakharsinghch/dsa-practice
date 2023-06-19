class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r=nums.size()-1;
        vector<int> res(nums.size());
        int i=nums.size()-1;
        while(l<=r){
            int sql = nums[l]*nums[l], sqr = nums[r]*nums[r];
            if(sql > sqr){
                res[i] = sql;
                i--;
                l++;
            }
            else{
                res[i] = sqr;
                i--;
                r--;
            }
        }

        return res;
    }
};