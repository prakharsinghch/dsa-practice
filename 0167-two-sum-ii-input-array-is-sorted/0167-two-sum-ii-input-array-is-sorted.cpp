class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int s = target-nums[i];
            int low = i+1;
            int high = nums.size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid] > s) high = mid-1;
                else if(nums[mid] < s) low = mid+1;
                else{
                    vector<int> v;
                    v.push_back(i+1);
                    v.push_back(mid+1);
                    return v;
                }
            }
        }

        return {};
    }
};