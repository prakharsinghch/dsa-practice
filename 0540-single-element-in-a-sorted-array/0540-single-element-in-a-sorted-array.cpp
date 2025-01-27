class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h =nums.size()-1;
        while(l<h){
            int mid = (l+h)/2;
            if(mid%2) mid--;
            if(nums[mid] != nums[mid+1]) h = mid;
            else l =mid+2;
        }
        return nums[l];
    }    
};