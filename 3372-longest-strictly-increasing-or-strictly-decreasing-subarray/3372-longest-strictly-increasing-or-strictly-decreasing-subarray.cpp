class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    
        int n = nums.size();
        int mxI = 1, mxD = 1;
        for(int i=0;i<n;i++){
            vector<int> x, y;
            x.push_back(nums[i]);
            y.push_back(nums[i]);
            for(int j=i;j<n;j++){
                if(i == j) continue;
                if(x.back() < nums[j]){
                    x.push_back(nums[j]);
                    int n1 = x.size();
                    mxI = max(mxI,n1);
                }
                else break;
            }
            for(int j=i;j<n;j++){
                if(i == j) continue;
                if(y.back() > nums[j]){
                    y.push_back(nums[j]);
                    int n1 = y.size();
                    mxD = max(mxD,n1);
                }
                else break;
            }
        }

        return max(mxD,mxI);
    }
};