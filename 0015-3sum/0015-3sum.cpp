class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int low,high;
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            low = i+1, high = n-1;
            while(low<high){
                if(nums[i] + nums[low] + nums[high] < 0) low++;
                else if(nums[i] + nums[low] + nums[high] >0) high--;
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    s.insert(v);
                    // ans.push_back(v);
                    // int tempIndex1 = low, tempIndex2 = high;
                    //  while(low < high && nums[low] == nums[tempIndex1]) low++;
                    // while(low < high && nums[high] == nums[tempIndex2]) high--;
                    low++;
                    high--;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }

        for(auto x:s){
            ans.push_back(x);
        }

        return ans;
        
    }
};