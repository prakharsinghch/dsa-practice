class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int x = INT_MAX,j=0;
        nums.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            nums.push_back(nums[i]);
            if(nums[i] < nums[i-1]) j = i ;
        }
        
        for(int i=j+1;i<j+n;i++){
            if(nums[i-1] > nums[i] ) return false;
        }


        return true;
    }
};