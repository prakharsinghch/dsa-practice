class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum =0,res=0;
        for(auto x: nums){
            sum+=x;
            if(sum > res) res = sum;
            if(sum < 0) sum = 0;
        }
        res = max(res,sum);
        
        int sum2 = 0,res2 = 0;
        for(auto x: nums){
            sum2+=x;
            if(sum2 < res2) res2 = sum2;
            if(sum2 > 0) sum2 = 0;
        }
        res2 = min(res2,sum2);
        res2 = abs(res2);

        return max(res2,res);
    }
};