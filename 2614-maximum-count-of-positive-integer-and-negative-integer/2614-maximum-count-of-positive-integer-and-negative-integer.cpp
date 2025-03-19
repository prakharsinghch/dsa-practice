class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=0,p=0;
        for(auto x: nums){
            if(x < 0) n++;
            else if(x > 0) p++;
        }

        return max(n,p);
    }
};