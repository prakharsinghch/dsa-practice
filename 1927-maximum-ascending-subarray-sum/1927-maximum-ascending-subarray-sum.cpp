class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int x =nums[i];
            sum = max(sum,x);
            for(int j=i+1;j<n;j++){
                if(nums[j-1] <nums[j] ){
                    x+=nums[j];
                    sum = max(sum,x);
                }else {
                    // i = j ;
                    break;
                }
            }
        }

        return sum;
    }
};