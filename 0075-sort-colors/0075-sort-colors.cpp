class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        for(auto x:nums){
            if(x==0) c0++;
            if(x==1) c1++;
            if(x==2) c2++;
        }
        for(int i=0;i<c0;i++) nums[i]=0;
        for(int i=c0;i<c0+c1;i++) nums[i]=1;
        for(int i=c0+c1;i<nums.size();i++) nums[i]=2;
    }
};