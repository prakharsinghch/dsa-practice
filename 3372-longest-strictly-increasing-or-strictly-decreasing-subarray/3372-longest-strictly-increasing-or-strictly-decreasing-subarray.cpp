class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mxI = 0, mxD = 0, c=1;
        int back = 0;
        for(int i=0;i<nums.size();i++){
            if(back >= nums[i]){
                c = 1;
            }
            back = nums[i];
            mxI = max(mxI,c++);
        }
        c =1;
        back = 0;
        for(int i=0;i<nums.size();i++){
            if(back <= nums[i]){
                c = 1;
            }
            back = nums[i];
            mxD = max(mxD,c++);
        }

        return max(mxI,mxD);
    }
};